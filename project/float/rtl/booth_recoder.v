/*
 * Kenneth Mayer (1401529)
 * krmayer@ucsc.edu
 * booth_recoder.v
 * This module performs Booth Recoding on the 3-bit input and returns the 
 * encoded value.
 */

module booth_recoder(
    input  [2:0] value_i,

    output reg negate_o,
    output reg zero_o,
    output reg shift_o
);
   
   always@(*) begin
      /* Encode the value */
      if(value_i == 3'b000) begin
         negate_o = 1'b0;
	 zero_o = 1'b1;
	 shift_o = 1'b0;
      end else if(value_i == 3'b001) begin
	 negate_o = 1'b0;
	 zero_o = 1'b0;
	 shift_o = 1'b0;
      end else if(value_i == 3'b010) begin
         negate_o = 1'b0;
	 zero_o = 1'b0;
	 shift_o = 1'b0;
      end else if(value_i == 3'b011) begin
         negate_o = 1'b0;
	zero_o = 1'b0;
	 shift_o = 1'b1;
      end else if(value_i == 3'b100) begin
         negate_o = 1'b1;
	 zero_o = 1'b0;
	 shift_o = 1'b1;
      end else if(value_i == 3'b101) begin
         negate_o = 1'b1;
	 zero_o = 1'b0;
	 shift_o = 1'b0;
      end else if(value_i == 3'b110) begin
        negate_o = 1'b1;
	 zero_o = 1'b0;
	 shift_o = 1'b0;
      end else if(value_i == 3'b111) begin
         negate_o = 1'b0;
	 zero_o = 1'b1;
	 shift_o = 1'b0;
      end
   end // always@ (*)
   
   
endmodule // booth_recoder

   
