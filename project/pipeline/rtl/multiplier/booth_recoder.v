/*
 * Kenneth Mayer (1401529)
 * krmayer@ucsc.edu
 * booth_recoder.v
 * This module performs Booth Recoding on the 3-bit input and returns the 
 * encoded value.
 */

module booth_recoder(
    input  [2:0] value_i,

    output negate_o,
    output zero_o,
    output shift_o
);
   reg 	 negate_o;
   reg 	 zero_o;
   reg 	 shift_o;
   
   always@(*) begin
      /* Encode the value */
      case(value_i)
	3'b000: negate_o = 1'b0;
	zero_o = 1'b1;
	shift_o = 1'b0;
	  
	3'b001: negate_o = 1'b0;
	zero_o = 1'b0;
	shift_o = 1'b0;
	  
	3'b010: negate_o = 1'b0;
	zero_o = 1'b0;
	shift_o = 1'b0;
	
	3'b011: negate_o = 1'b0;
	zero_o = 1'b0;
	shift_o = 1'b1;
	
	3'b100: negate_o = 1'b1;
	zero_o = 1'b0;
	shift_o = 1'b1;
	
	3'b101: negate_o = 1'b1;
	zero_o = 1'b0;
	shift_o = 1'b0;
	
	3'b110: negate_o = 1'b1;
	zero_o = 1'b0;
	shift_o = 1'b0;
	
	3'b111: negate_o = 1'b0;
	zero_o = 1'b1;
	shift_o = 1'b0;
      endcase // case (value_i)
   end

endmodule // booth_recoder

   
