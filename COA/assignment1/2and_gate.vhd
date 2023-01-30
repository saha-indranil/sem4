-- 2. Write down the VHDL program of two input AND gate with data flow model.

library IEEE;
use IEEE.std_logic_1164.all;

entity andgate is
    port(
        A:in std_logic; 
        B:in std_logic; 
        Y:out std_logic);
end andgate;

architecture andlogic of andgate is
begin
    Y<=A AND B;
end andlogic;
