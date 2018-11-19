/* Modified to allow loading a value */

module flop
  #(parameter Bits=1)
  (  input clk
    ,input reset
    ,input load
    ,input [Bits-1:0] load_val
    ,input [Bits-1:0] d
    ,output reg [Bits-1:0] q
  );

  always @(posedge clk) begin
    if (reset)
      q <= 'b0;
    else if (load)
      q <= load_val;
    else
      q <= d;
  end

endmodule

