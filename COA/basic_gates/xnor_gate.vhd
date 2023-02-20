-- 7. Write down the VHDL program of three input XNOR gate with data flow model.
 
library IEEE;
use IEEE.std_logic_1164.all;

entity xnorgate is
    port(
        A:in std_logic; 
        B:in std_logic; 
        C:in std_logic; 
        Y:out std_logic);
end xnorgate;

architecture xnorlogic of xnorgate is
begin
    Y<=not(A xor B xor C);
end xnorlogic;