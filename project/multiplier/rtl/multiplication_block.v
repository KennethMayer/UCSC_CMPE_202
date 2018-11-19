/* verilator lint_off UNUSED */
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
    output [64-1:0] product_low_o,
    output [64-1:0] product_high_o
);
    
   reg [128-1:0]    partial, partial_next;
   reg [64-1:0]     product_low_next;
   reg [64-1:0]     product_high_next;
   reg [64-1:0]     current;
   reg [64-1:0]     temp;
   reg [5:0] 	    index, index_next;
   reg [5:0] 	    leading_one, leading_one_next;
   reg [2:0] 	    recode, recode_next;
   reg 		    pending, pending_next;
   reg 		    done_next;
   
   wire 	    negate, zero, shift;
   
   always @(*) begin
      leading_one_next = leading_one;
      recode_next = recode;
      index_next = index;
      current = 64'b0;
      partial_next = partial;
      done_next = done_o;
      product_high_next = product_high_o;
      product_low_next = product_low_o;
      temp = 64'b0;
      if(start_i && pending != 1'b1) begin
	 find_leading_one(multiplicand_i, leading_one_next);
	 pending_next = 1'b1;
	 recode_next = {multiplicand_i[1:0], 1'b0};
	 index_next = 6'd1;
      end else if(pending) begin
	 if(zero) begin
	    current = 64'b0;
	 end else begin 
	    if(negate) begin
	       current = $signed(-multiplier_i);
	    end else begin
	       current = $signed(multiplier_i);
	    end if(shift)
	      current = $signed(current << 1'b1);
	 end // else: !if(zero)
	 partial_next = $signed({{64{current[63]}}, current} << (index - 7'd1)) + $signed(partial);
	 temp = (multiplicand_i >> index);
	 recode_next = temp[2:0];
	 index_next = index + 6'd2;
	 if(index_next > 6'd61 || leading_one < index)
	   pending_next = 1'b0;
	 else
	   pending_next = pending;
      end else begin // if (pending = 1'b1)
	 done_next = 1'b1;
	 product_low_next = partial[63:0];
	 product_high_next = partial[127:64];
	 pending_next = 1'b0;
      end
   end // always @ (*)

   task find_leading_one;
      input [64-1:0] value;
      output [5:0]   leading_one_out;
      integer 	     i;
      begin
	 leading_one_out = 6'b0;
	 for(i=63; i >= 0; i=i-1) begin
	    if(value[i[5:0]] == 1'b1 && leading_one_out == 6'b0) begin
	       leading_one_out = i[5:0];
	    end
	 end
      end
   endtask // find_leading_one
   
   flop
     #(.Bits(64)) product_low_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (64'b0),
	.d        (product_low_next),
	.q        (product_low_o)
	);
   
   flop
     #(.Bits(64)) product_high_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (64'b0),
	.d        (product_high_next),
	.q        (product_high_o)
	);

  flop
     #(.Bits(128)) partial_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (128'b0),
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
	.load     (1'b0),
	.load_val (3'b0),
	.d        (recode_next),
	.q        (recode)
	);

   flop
     #(.Bits(6)) recode_index_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (6'b0),
	.d        (index_next),
	.q        (index)
	);

   flop
     #(.Bits(6)) leading_one_flop
       (.clk      (clk),
	.reset    (reset_i),
	.load     (1'b0),
	.load_val (6'b0),
	.d        (leading_one_next),
	.q        (leading_one)
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

   booth_recoder
     recoder
       (.value_i  (recode),
	.negate_o (negate),
	.zero_o   (zero),
	.shift_o  (shift)
	);
   
endmodule // multiplication_block
/* verilator lint_off UNUSED */
