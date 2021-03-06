/* verilator lint_off UNUSED */
/* 
 * Kenneth Mayer (1401529)
 * krmayer@ucsc.edu
 * division_block.v
 * This module performs multi-cycle division on its two operands and returns the result
 * when it is ready, along with a 'done' signal.
 * Credit: algorithm adapted from http://www.ece.lsu.edu/ee3755/2012f/l07.v.html
 */

module division_block(
    input 	    clk,
    input 	    reset_i,

    input 	    start_i,
    input [64-1:0]  dividend_i, 
    input [64-1:0]  divisor_i,

    output 	    done_o,
    output [64-1:0] quotient_o,
    output [64-1:0] remainder_o 
);

   reg 		    done_next;
   reg [64-1:0]     quotient_next;
   reg [128-1:0]    remainder, remainder_next;
   reg [64-1:0]     dividend, dividend_next; /* holds absolute value of dividend */
   reg [64-1:0]     divisor, divisor_next; /* holds absolute value of divisor */
   reg 		    pending, pending_next;
   reg [65-1:0]     diff;

   /* sign of the output; 1 = negative, 0 = positive  */
   reg 		    sign, sign_next;

   reg [6:0] 	    index, index_next;
   
   always @(*) begin
      pending_next = pending;
      done_next = done_o;
      quotient_next = quotient_o;
      pending_next = pending;
      dividend_next = dividend;
      divisor_next = divisor;
      index_next = index;
      sign_next = sign;
      if(start_i && !pending) begin
	 pending_next = 1'b1;
	 
	 /* Divide by zero detection  */
	 if(divisor_i == 64'b0) begin
	    done_next = 1'b1;
	    quotient_next = 64'hFFFFFFFFFFFFFFFF;
	    pending_next = 1'b0;
	 end
	 
	 sign_next = ($signed(dividend_i) < $signed(64'b0)) ^ ($signed(divisor_i) < $signed(64'b0));

	 /* Take the absolute value of the operands */
	 if($signed(dividend_i) < $signed(64'b0))
	   dividend_next = ~(dividend_i) + 64'b1;
	 else
	   dividend_next = dividend_i;
	 
	 if($signed(divisor_i) < $signed(64'b0))
	   divisor_next = ~(divisor_i) + 64'b1;
	 else
	   divisor_next = divisor_i;
	 
	 index_next = 7'd63;
	 remainder_next[63:0] = dividend_next;
      end else if(pending) begin // if (start_i && !pending)
	 diff = remainder[127:63] - {1'b0, divisor};
	 if(diff[64])
	   remainder_next = {remainder[126:0], 1'b0};
	 else
	   remainder_next = {diff[63:0], remainder[62:0], 1'b1};
	 index_next = index - 1;
	 if(index == 7'b0)
	   pending_next = 1'b0;
      end else begin
	 if(sign)
	   remainder_next[63:0] = ~(remainder[63:0]) + 64'b1;
	 done_next = 1'b1;
      end
      
   end

   flop
     #(.Bits(64)) dividend_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (64'b0),
	.d        (dividend_next),
	.q        (dividend)
	);

   flop
     #(.Bits(64)) divisor_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (64'b0),
	.d        (divisor_next),
	.q        (divisor)
	);

   
   flop
     #(.Bits(64)) quotient_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (64'b0),
	.d        (remainder_next[63:0]),
	.q        (quotient_o)
	);

   flop
     #(.Bits(64)) remainder_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (64'b0),
	.d        (remainder_next[127:64]),
	.q        (remainder_o)
	);

   flop
     #(.Bits(128)) remainder_int_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (128'b0),
	.d        (remainder_next),
	.q        (remainder)
	);

   flop
     #(.Bits(7)) index_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (7'b0),
	.d        (index_next),
	.q        (index)
	);

   flop
     #(.Bits(1)) pending_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (1'b0),
	.d        (pending_next),
	.q        (pending)
	);

   flop
     #(.Bits(1)) done_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (1'b0),
	.d        (done_next),
	.q        (done_o)
	);

   flop
     #(.Bits(1)) sign_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (1'b0),
	.d        (sign_next),
	.q        (sign)
	);
   
endmodule // division_block
/* verilator lint_off UNUSED */
