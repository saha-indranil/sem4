-- 4. Write down the VHDL program of three input NAND gate with data flow model.

library IEEE;
use IEEE.std_logic_1164.all;

entity nandgate is
    port(
        A:in std_logic; 
        B:in std_logic; 
        C:in std_logic; 
        Y:out std_logic);
end nandgate;

architecture nandlogic of nandgate is
begin
    Y<=not(A and B and C);
end nandlogic;
