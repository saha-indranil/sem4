-- 6. Write down the VHDL program of three input XOR gate with data flow model.

library IEEE;
use IEEE.std_logic_1164.all;

entity xorgate is
    port(
        A:in std_logic; 
        B:in std_logic; 
        C:in std_logic; 
        Y:out std_logic);
end xorgate;

architecture xorlogic of xorgate is
begin
    Y<=A xor B xor C;
end xorlogic;
