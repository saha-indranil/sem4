-- 3. Design full adder using VHDL.

library IEEE;
use IEEE.std_logic_1164.all;

entity full_adder is
    port(
        a, b, c : in std_logic; 
        sum, carry : out std_logic);
end full_adder;

architecture Behavioral of full_adder is
begin
    sum <= a xor b xor c;
    carry <= (a and b) or (b and c) or (c and a);
end Behavioral;