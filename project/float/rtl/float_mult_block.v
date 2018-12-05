/* Bus macros */
`define EXP 30:23 // exponent
`define MAN 22:0 // mantissa
`define SN 31 // sign

module float_mult_block(
			input 	       clk,
			input 	       reset_i,

			input 	       start_i,
			input [32-1:0] float1_i,
			input [32-1:0] float2_i,

			output reg     done_o,
			output 	       red [32-1:0] float_o
			);
   wire 			       done;
   wire [

   always @(*) begin
      
   end

   multiplication_block man_multiplier
     (.clk (clk), .reset_i(reset_i), .start_i(start_i), .multiplier_i(), .multiplicand_i(), .done_o(done)
endmodule // float_mult_block

