/* 
 * Kenneth Mayer (1401529)
 * krmayer@ucsc.edu
 * multiplication_block.v
 * This module performs multi-cycle multiplication on its two operands and returns the result
 * when it is ready, along with a 'done' signal.
 */

module multiplication_block(
    input 	    clk,
    input 	    reset_i,

    input 	    start_i,
    input [64-1:0]  multiplier_i, 
    input [64-1:0]  multiplicand_i,

    output 	    done_o,
    output [64-1:0] product_o
);
    
   reg [64-1:0]     partial, partial_next;
   reg [64-1:0]     product_next;
   reg [64-1:0]     current;
   reg [7:0] 	    index, index_next;
   
   reg 		    done_next;
   
   reg [3:0] 	    recode, recode_next;
   reg 		    pending, pending_next;
   reg 		    error, error_next;
   
   wire 	    negate, zero, shift;
   
   always @(*) begin
      recode_next = recode;
      index_next = index;
      current = 64'b0;
      partial_next = partial;
      done_next = done_o;
      product_next = product_o;
      if(start_i) begin
	 pending_next = 1'b1;
	 recode_next = {multiplicand_i[1:0], 1'b0};
	 index_next = 7'd1;
      end else if(pending = 1'b1) begin
	 if(zero) begin
	    current = 64'b0;
	 end else begin 
	    if(negate) begin
	       current = $signed(~multiplier_i + 1);
	    end else begin
	       current = $signed(multiplier_i);
	    end if(shift)
	      current = $signed(partial_next) << 1'b1;
	 end
	 partial_next = $signed(current) << (index - 7'd1) + $signed(partial);
	 recode_next = (multiplicand >> index)[2:0];
	 index_next = index + 7'd2;
	 if(index_next > 7'd61)
	   pending_next = 1'b0;
	 else
	   pending_next = pending;
      end else begin // if (pending = 1'b1)
	 done_next = 1'b1;
	 product_next = partial;
	 pending_next = 1'b0;
      end
   end // always @ (*)

flop
     #(.Bits(64)) product_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (64'b0),
	.d        (product_next),
	.q        (product_o)
	);

  flop
     #(.Bits(64)) partial_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (64'b0),
	.d        (partial_next),
	.q        (partial)
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
     #(.Bits(3)) recode_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (3'b0),
	.load_val (3'b0),
	.d        (recode_next),
	.q        (recode)
	);

   flop
     #(.Bits(7)) recode_index_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (3'b0),
	.load_val (3'b0),
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
     #(.Bits(1)) error_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (1'b0),
	.d        (error_next),
	.q        (error)
	);

   booth_recoder
     recoder
       (.value_i  (recode),
	.negate_o (negate),
	.zero_o   (zero),
	.shift_o  (shift)
	);
   
endmodule // multiplication_block