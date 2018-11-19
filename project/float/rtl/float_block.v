/* verilator lint_off UNUSED */
/* 
 * Kenneth Mayer (1401529)
 * krmayer@ucsc.edu
 * float_block.v
 * This module performs many operations on two full-precision floating point number based on
 * the input opcode. Some of them may take more than one clock cycle.
 * 0 = FLW.S (load word)
 * 1 = FSW.S (store word)
 * 2 = FMADD.S (fused multiply-add)
 * 3 = FMSUB.S (fused multiply-sub)
 * 4 = FNMSUB.S (fused multiply-sub negative)
 * 5 = FNMADD.S (fused multiply-add negative
 * 6 = FADD.S (add)
 * 7 = FSUB.S (subtract)
 * 8 = FMUL.S (mutliply)
 * 9 = FDIV.S (divide)
 * 10 = FSQRT.S (square-root)
 * 11 = FSGNJ.S (sign-injection)
 * 12 = FSGNJN.S (sign-injection negation)
 * 13 = FSGNJX.S (sign-injection xor)
 * 14 = FMIN.S (write smaller operand to dest)
 * 15 = FMAX.S (write larger operand to dest)
 * 16 = FCVT.W.S (convert float to int32)
 * 17 = FCVT.WU.S (convert float to uint32)
 * 18 = FMV.X.W (move float to lower 32 of int reg; upper 32 are float's sign bit)
 * 19 = FEQ.S (if equal, put 1 into int reg)
 * 20 = FLT.S (if rs1 < rs2, put 1 into int reg)
 * 21 = FLE.S (if rs1 <= rs2, put 1 into int reg)
 * 22 = FCLASS.S (classifies float in rs1 and writes 10-bit mask to int reg)
 * 23 = FCVT.S.W (convert int32 to float)
 * 24 = FCVT.S.WU (convert uint32 to float)
 * 25 = FMV.W.X (move float from lower 32 of int reg)
 * 26 = FCVT.L.S (convert float to int64)
 * 27 = FCVT.LU.S (convert float to uint64)
 * 28 = FCVT.S.L (convert int64 to float)
 * 29 = FCVT.S.LU (convert unint64 to float)
 * 30, 31 = invalid
 */

/* Zero */
`define ZERO 31'h0 // compare only the bottom 31 bits

/* Canonical NaN */
`define NAN_CANON 32'h7fc00000

/* Ranges for a quiet NaN */
`define QNAN_LOW_1 32'h7fc00000
`define QNAN_HIGH_1 32'h7fffffff
`define QNAN_LOW_2 32'hffc00000
`define QNAN_HIGH_2 32'hffffffff

/* Ranges for a signaled NaN */
`define SNAN_LOW_1 32'h7f800001
`define SNAN_HIGH_1 32'h7FBFFFFF
`define SNAN_LOW_2 32'hFF800001
`define SNAN_HIGH_2 32'hFFBFFFFF

/* Positive and negative infinity */
`define INF  32'h7ff00000
`define NINF 32'hfff00000

/* Bus macros */
`define EXP 30:23 // exponent
`define MAN 22:0 // mantissa
`define SN 31 // sign

module float_block(
    input 		clk,
    input 		reset_i,

    input 		start_i,
    input [32-1:0] 	float1_i, 
    input [32-1:0] 	float2_i,
    input [32-1:0] 	float3_i,
    input [5-1:0] 	opcode_i,

    output reg 		done_o,
    output reg [4-1:0] 	exceptions_o,
    output reg [32-1:0] float_low_o,
    output reg [32-1:0] float_high_o,
    output reg [64-1:0] int_o
    );

  /* wire 	    float1_sign, float2_sign, float3_sig;n
   wire [7:0] 	    float1_exponent, float2_exponent, float3_exponent;
   wire [22:0] 	    float1_mantissa, float2_mantissa, float3_mantissa;

   assign float1_sign = float1_i[`SN];
   assign float2_sign = float2_i[`SN];
   assign float3_sign = float3_i[`SN];

   assign float1_exponent = float1_i[`EXP];
   assign float2_exponent = float2_i[`EXP];
   assign float3_exponent = float3_i[`EXP];

   assign float1_mantissa = float1_i[`MAN];
   assign float2_mantissa = float2_i[`MAN];
   assign float3_mantissa = float3_i[`MAN];*/
   
   always @(*) begin
      done_o = 1'b0;
      exceptions_o = 4'b0;
      float_low_o = 32'b0;
      float_high_o = 32'b0;
      int_o = 64'b0;
      if(start_i) begin
	 case(opcode_i)
	   5'd0: begin // FLW.S
	   end
	   5'd1: begin // FSW.S
	   end
	   5'd2: begin // FMADD.S
	   end
	   5'd3: begin // FMSUB.S
	   end
	   5'd4: begin // FNMSUB.S
	   end
	   5'd5: begin // FNMADD.S
	   end
	   5'd6: begin // FADD.S
	      float_low_o = addFloats(float1_i, float2_i);
	      done_o = 1'b1;
	   end
	   5'd7: begin // FSUB.S
	      float_low_o = addFloats(float1_i, {float2_i[`SN] + 1'b1, float2_i[30:0]});
	      done_o = 1'b1;
	   end
	   5'd8: begin // FMUL.S
	   end
	   5'd9: begin // FDIV.S
	   end
	   5'd10: begin // FSQRT.S
	   end
	   5'd11: begin // FSGNJ.S
	   end
	   5'd12: begin // FSGNJN.S
	   end
	   5'd13: begin // FSGNJX.S
	   end
	   5'd14: begin // FMIN.S
	      float_low_o = minFloat(float1_i, float2_i);
	      done_o = 1'b1;
	   end
	   5'd15: begin // FMAX.S
	      float_low_o = maxFloat(float1_i, float2_i);
	      done_o = 1'b1;
	   end
	   5'd16: begin // FCVT.W.S
	   end
	   5'd17: begin // FCVT.WU.S
	   end
	   5'd18: begin // FMV.X.W
	   end
	   5'd19: begin // FEQ.S
	      int_o = {63'b0, floatEquality(float1_i, float2_i)};
	      done_o = 1'b1;
	   end
	   5'd20: begin // FLT.S
	      int_o = {63'b0, floatLess(float1_i, float2_i)};
	      done_o = 1'b1;
	   end
	   5'd21: begin // FLE.S
	      int_o = {63'b0, floatLess(float1_i, float2_i) || floatEquality(float1_i, float2_i)};
	      done_o = 1'b1;
	   end
	   5'd22: begin // FCLASS.S
	      int_o = {54'b0, classifyFloat(float1_i)};
	      done_o = 1'b1;
	   end
	   5'd23: begin // FCVT.S.W
	   end
	   5'd24: begin // FCVT.S.WU
	   end
	   5'd25: begin // FMV.W.X
	   end
	   5'd26: begin // FCVT.L.S
	   end
	   5'd27: begin // FCVT.LU.S
	   end
	   5'd28: begin // FCVT.S.L
	   end
	   5'd29: begin // FCVT.S.LU
	   end
	   default: begin
	   end
	 endcase // case (opcode_i)
      end
   end // always @(*)
   
   /* This function operates returns 1 if float1 < float2, zero otherwise */
   function floatEquality;
      input [32-1:0] float_in1;
      input [32-1:0] float_in2;
      begin
	 if(float_in1[`EXP] == float_in2[`EXP] && float_in1[`MAN] == float_in2[`MAN] && float_in1[`SN] == float_in2[`SN])
	   floatEquality = 1'b1;
	 else if(float_in1[30:0] == float_in2[30:0] && float_in1[30:0] == `ZERO)
	   floatEquality = 1'b1;
	 else if((float_in1 == `INF && float_in2 == `INF) || (float_in1 == `NINF && float_in2 == `NINF))
	   floatEquality = 1'b1;
	 else
	   floatEquality = 1'b0;
	 if((isNan(float_in1) > 2'b0) || (isNan(float_in2) > 2'b0)) // NaN does not equal NaN
	   floatEquality = 1'b0;
      end
   endfunction // floatEquality

   /* This function returns 1 if float1 < float2, zero otherwise */
   function floatLess;
      input [32-1:0] float_in1;
      input [32-1:0] float_in2;
      begin
	 if(float_in1[`EXP] < float_in2[`EXP]) // compare exponents
	   floatLess = 1'b1;
	 else if(float_in1[`EXP] == float_in2[`EXP]) begin // if equal, compare mantissas
	    if(float_in1[`MAN] < float_in2[`MAN])
	      floatLess = 1'b1;
	    else
	      floatLess = 1'b0;
	 end else if(float_in1 == `NINF) // check for the special case of negative infinity; equality is checked later
	   floatLess = 1'b1;
	 else if(float_in1 == `INF) // check for the special case of infinity; equality is checked later
	   floatLess = 1'b0;
	 else
	   floatLess = 1'b0;
	 if(float_in1[`SN] > float_in2[`SN]) // this is correct, except if both are zero; the function call below checks that.
	   floatLess = 1'b1;
	 else if(float_in1[`SN] < float_in2[`SN])
	   floatLess = 1'b0;
	 if(floatEquality(float_in1, float_in2))
	   floatLess = 1'b0;
	 if((isNan(float_in1) > 2'b0) || (isNan(float_in2) > 2'b0)) // NaNs have no relation to anything
	   floatLess = 1'b0;
      end
   endfunction // floatLess

   /* This function returns 1 if the input is a quiet NaN, 2 if it is a signaling NaN, 0 otherwise. */
   function [2-1:0] isNan;
      input [32-1:0] float_in;
      begin
	 isNan = 2'b0;
	 if((float_in <= `QNAN_HIGH_1 && float_in >= `QNAN_LOW_1) ||  float_in >= `QNAN_LOW_2)
	   isNan = 2'b01;
	 if((float_in <= `SNAN_HIGH_1 && float_in >= `SNAN_LOW_1) || (float_in <= `SNAN_HIGH_2 && float_in >= `SNAN_LOW_2)) begin
	    isNan = 2'b10;
	 end
      end
   endfunction // isNan

   /* This function takes a float and returns the 10-bit mask that classifies the float (from the RISCV spec) */
   function [10-1:0] classifyFloat;
      input [32-1:0] float_in;
      begin
	 reg [9:0] mask = 10'b0;
	 if(float_in == `NINF) // negative infinity
	      mask[0] = 1'b1;
	 if(float_in[`EXP] != 8'b0 && float_in[`SN] == 1'b1) // negative normal number
	      mask[1] = 1'b1;
	 if(float_in[`EXP] == 8'b0 && float_in[`SN] == 1'b1) // negative subnormal number
	      mask[2] = 1'b1;
	 if(float_in[`EXP] == 8'b0 && float_in[`SN] == 1'b0) // positive subnormal number
	      mask[5] = 1'b1;
	 if(float_in[`EXP] != 8'b0 && float_in[`SN] == 1'b0) // positive normal number
	      mask[6] = 1'b1;
	 if(float_in[30:0] == 31'b0 && float_in[`SN] == 1'b1) begin // negative zero
	    mask[3] = 1'b1;
	    mask[2] = 1'b0; // If it's zero, it's not subnormal
	    mask[5] = 1'b0;
	 end
	 if(float_in[30:0] == 31'b0 && float_in[`SN] == 1'b0) begin // positive zero
	    mask[4] = 1'b1;
	    mask[2] = 1'b0; // If it's zero, it's not subnormal
	    mask[5] = 1'b0;
	 end
	 if(float_in == `INF) // positive infnity
	      mask[7] = 1'b1;
	 if(isNan(float_in) == 2'b01) // quiet NaN
	      mask[8] = 1'b1;
	 if(isNan(float_in) == 2'b10) // signaling NaN
	      mask[9] = 1'b1;
	 classifyFloat = mask;
      end
   endfunction // classifyFloat

   /* This function adds the two inputs to the function and returns the result. */
   function [32-1:0] addFloats;
      input [32-1:0] float_in1;
      input [32-1:0] float_in2;
      begin
	 reg [32-1:0] result;
	 reg [24-1:0] man_inter;
	 reg [5-1:0]  lead_one;
	 // start by adding the two, assuming both are normal numbers
	 if(float_in1[`EXP] == float_in2[`EXP]) begin
	    //$display("addFloats: both exponents equal");
	    if(float_in1[`SN] == float_in2[`SN]) begin
	       //$display("addFloats: same sign");
	       result[`EXP] = float_in1[`EXP] + 8'b1;
	       man_inter = {1'b0, float_in1[`MAN]} + {1'b0, float_in2[`MAN]};
	       man_inter = round_man_inter(man_inter);
	       man_inter = man_inter >> 1;
	       result[`MAN] = man_inter[22:0];
	       result[`SN] = float_in1[`SN];
	    end else if(float_in1[`SN] > float_in2[`SN]) begin
	       //$display("addFloats: float1 negative");
	       man_inter = $signed({1'b0, float_in2[`MAN]}) - $signed({1'b0, float_in1[`MAN]});
	       /* if man_inter became negative, make it positive again */
	       if($signed(man_inter) < $signed(24'b0)) begin
		  result[`SN] = 1'b1;
		  man_inter = ~(man_inter) + 24'd1;
	       end
	       /* man_inter is not normalized. The leading one will become the hidden 1 bit in the result. */
	       lead_one = findLeadOne(man_inter);
	       result[`EXP] = float_in1[`EXP] - (8'd23 - {2'b0, lead_one} + 8'd1);
	       /* shift man_inter to re-normalize it */
	       result[`MAN] = man_inter[22:0] << {6'd24 - lead_one};
	    end else begin // if (float_in1[`SN] > float_in2[`SN])
	       //$display("addFloats: float2 negative");
	       man_inter = $signed({1'b0, float_in1[`MAN]}) - $signed({1'b0, float_in2[`MAN]});
	       if($signed(man_inter) < $signed(24'b0)) begin
		  result[`SN] = 1'b1;
		  man_inter = ~(man_inter) + 23'd1;
	       end
	       lead_one = findLeadOne(man_inter);
	       result[`EXP] = float_in1[`EXP] - (8'd23 - {2'b0, lead_one} + 8'd1);
	       result[`MAN] = man_inter[22:0] << (6'd24 - lead_one);	       
	    end
	 end else begin // if (float_in1[`EXP] == float_in2[`EXP])
	    if(float_in1[`EXP] < float_in2[`EXP]) begin /* float_in2 has the larger exponent */
	        //$display("addFloats: float2 has the larger exponent");
	       /* In this case, we must shift the mantissa of the smaller exponent, along with its hidden 1 */
	       man_inter = {1'b1, float_in1[`MAN]} >> (float_in2[`EXP] - float_in1[`EXP]);
	       /* now, we add this to the other mantissa */
	       if(float_in1[`SN] == float_in2[`SN]) begin
		  //$display("addFloats: same sign");
		  man_inter = man_inter + {1'b0, float_in2[`MAN]};
		  result[`EXP] = float_in2[`EXP] + {7'b0, man_inter[23]}; // means there was a carry when adding the 22nd bits of the intermediate mantissa.
		  if(man_inter[23]) begin
		     man_inter[23] = 1'b0; // this would be the result if we included the hidden 1 of the number with the larger exponent
		     man_inter = round_man_inter(man_inter);
		     man_inter = man_inter >> 1;
		  end
		  result[`MAN] = man_inter[22:0];
		  result[`SN] = float_in1[`SN];
	       end else if(float_in1[`SN] > float_in2[`SN]) begin
		  //$display("addFloats: float1 negative");
		  man_inter =  $signed({1'b0, float_in2[`MAN]}) - $signed(man_inter);
		  if($signed(man_inter) < $signed(24'b0)) begin
		     result[`SN] = 1'b1;
		     man_inter = ~(man_inter) + 24'd1;
		  end else
		    result[`SN] = 1'b0;
		  lead_one = findLeadOne(man_inter);
		  result[`EXP] = float_in2[`EXP] - (8'd23 - {2'b0, lead_one});
		  result[`MAN] = man_inter[22:0] << (6'd23 - lead_one);
	       end else begin // if (float_in1[`SN] > float_in2[`SN])
		  //$display("addFloats: float2 negative");
		  man_inter = $signed({1'b0, float_in2[`MAN]}) - $signed(man_inter);
		  if($signed(man_inter) < $signed(24'b0)) begin
		     result[`SN] = 1'b1;
		     man_inter = ~(man_inter) + 24'd1;
		  end		  
		  lead_one = findLeadOne(man_inter);
		  result[`EXP] = float_in2[`EXP] - (8'd23 - {2'b0, lead_one});
		  result[`MAN] = man_inter[22:0] << (6'd23 - lead_one);
	       end
	    end else begin // if (float_in1[`EXP] < float_in2[`EXP])
	       /* float_in1 has the larger exponent */
	       //$display("addFloats: float1 has the larger exponent");
	       man_inter = {1'b1, float_in2[`MAN]} >> (float_in1[`EXP] - float_in2[`EXP]);
	       if(float_in1[`SN] == float_in2[`SN]) begin
		  //$display("addFloats: same signs");
		  man_inter = man_inter + {1'b0, float_in1[`MAN]};
		  result[`EXP] = float_in1[`EXP] + {7'b0, man_inter[23]};
		  if(man_inter[23]) begin
		     man_inter[23] = 1'b0;
		     man_inter = round_man_inter(man_inter);
		     man_inter = man_inter >> 1;
		  end
		  result[`MAN] = man_inter[22:0];
		  result[`SN] = float_in1[`SN];
	       end else if(float_in1[`SN] > float_in2[`SN]) begin
		  //$display("addFloats: float1 negative");
		  man_inter = $signed(man_inter) - $signed({1'b0, float_in1[`MAN]});
		  if($signed(man_inter) < $signed(24'b0)) begin
		     result[`SN] = 1'b1;
		     man_inter = ~(man_inter) + 24'd1;
		  end else
		    result[`SN] = 1'b0;
		  lead_one = findLeadOne(man_inter);
		  result[`EXP] = float_in1[`EXP] - (8'd23 - {2'b0, lead_one});
		  result[`MAN] = man_inter[22:0] << (6'd23 - lead_one);
	       end else begin // if (float_in1[`SN] > float_in2[`SN])
		  //$display("addFloats: float2 negative");
		  man_inter = $signed({1'b0, float_in1[`MAN]}) - $signed(man_inter);
		  if($signed(man_inter) < $signed(24'b0)) begin
		     result[`SN] = 1'b1;
		     man_inter = ~(man_inter) + 24'd1;
		  end		  
		  lead_one = findLeadOne(man_inter);
		  result[`EXP] = float_in1[`EXP] - (8'd23 - {2'b0, lead_one});
		  result[`MAN] = man_inter[22:0] << (6'd23 - lead_one);
	       end
	    end // else: !if(float_in1[`EXP] < float_in2[`EXP])
	 end // else: !if(float_in1[`EXP] == float_in2[`EXP])
	 //$display("addFloats: result: %b", result);
	 addFloats = result;
      end
   endfunction // addFloats

   /* This function determines the larger of the two floats and returns the value. If they are equal, return either value. */
   function [32-1:0] maxFloat;
      input [32-1:0] float_in1;
      input [32-1:0] float_in2;
      begin
	 if(minFloat(float_in1, float_in2) == float_in1)
	   maxFloat = float_in2;
	 else
	   maxFloat = float_in1;

	 if(isNan(float_in1) == 2'b10 || isNan(float_in2) == 2'b10) begin /* If either input is a signaling NaN */
	    maxFloat = `NAN_CANON;
	 end else if(isNan(float_in1) == 2'b1 && isNan(float_in2) == 2'b1) begin /* If both inputs are a quiet NaN */
	    maxFloat = `NAN_CANON;
	 end else if(isNan(float_in1) == 2'b1 ^ isNan(float_in2) == 2'b1) begin /* if one, but not both are a quiet NaN */
	    if(isNan(float_in1) == 2'b1)
	      maxFloat = float_in2;
	    else
	      maxFloat = float_in1;
	 end	 
      end
   endfunction // maxFloat
   
   /* This function determines the smaller of the two floats and returns the value. If they are equal, return either value. */
   function [32-1:0] minFloat;
      input [32-1:0] float_in1;
      input [32-1:0] float_in2;
      begin
	 if(floatEquality(float_in1, float_in2))
	   minFloat = float_in1;
	 else if(floatLess(float_in1, float_in2))
	   minFloat = float_in1;
	 else
	   minFloat = float_in2;

	 if(isNan(float_in1) == 2'b10 || isNan(float_in2) == 2'b10) begin /* If either input is a signaling NaN */
	    minFloat = `NAN_CANON;
	 end else if(isNan(float_in1) == 2'b1 && isNan(float_in2) == 2'b1) begin /* If both inputs are a quiet NaN */
	    minFloat = `NAN_CANON;
	 end else if(isNan(float_in1) == 2'b1 ^ isNan(float_in2) == 2'b1) begin /* if one, but not both are a quiet NaN */
	    if(isNan(float_in1) == 2'b1)
	      minFloat = float_in2;
	    else
	      minFloat = float_in1;
	 end
      end
   endfunction // minFloat

   /* This function determines the leading one of a number. Used for normalizing the intermediate mantissa. */
   function [5-1:0] findLeadOne;
      input [24-1:0] num;
      begin
	 integer i;
	 for(i=0; i < 24; i=i+1) begin
	    if(num[i] == 1'b1)
	      findLeadOne = i[5-1:0];
	 end
      end
   endfunction // findLeadOne

   /* This function rounds the intermediate mantissa to the nearest even value */
   /* What if the mantissa is all 1s? Set all to zero and increase exponent, add support later. */
   function [24-1:0] round_man_inter;
      input [24-1:0] man_inter_in;
      begin
	 $display("intermediate mantissa: %b", man_inter_in);
	 if(man_inter_in >= 24'h100000 && man_inter_in[1] == 1'b1) begin
	    $display("rounding");
	    if(man_inter_in[0] == 1'b1)
	      round_man_inter = man_inter_in + 24'b1;
	    else
	      round_man_inter = man_inter_in + 24'b10;
	 end else
	   round_man_inter = man_inter_in;
	 
	 /*reg [5-1:0] trail_zero;
	 $display("Starting man_inter: %b", man_inter_in);
	 if(man_inter_in[0] == 1'b0)
	   round_man_inter = man_inter_in;
	 else begin
	    integer i;
	    for(i=23; i>32'b0; i=i-1) begin
	       if(man_inter_in[i] == 1'b0)
		 trail_zero = i[5-1:0];
	    end
	    for(i=0; i<{27'b0, trail_zero}; i=i+1) // set the bits before the trailing zero to 0
	      man_inter_in[i] = 1'b0;
	    man_inter_in = man_inter_in | (24'b1 << trail_zero); // set the bit with the trailing zero to 1
	    round_man_inter = man_inter_in;
	 end*/
      end
   endfunction // round_man_inter
   
endmodule // float_block
/* verilator lint_off UNUSED */
