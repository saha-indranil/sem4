-- 4. Design full subtractor using VHDL.

library IEEE;
use IEEE.std_logic_1164.all;

entity full_subtractor is
    port(
        a, b, cin : in std_logic; 
        diff, borrow : out std_logic);
end full_subtractor;

architecture Behavioral of full_subtractor is
begin
    diff <= a xor b xor cin;
    borrow <= ((not a) and b) or ((not a) and cin) or (b and cin);
end Behavioral;