-- 3. Write down the VHDL program of two input OR gate with data flow model.

library IEEE;
use IEEE.std_logic_1164.all;

entity orgate is
    port(
        A:in std_logic; 
        B:in std_logic; 
        Y:out std_logic);
end orgate;

architecture orlogic of orgate is
begin
    Y<=A or B;
end orlogic;
