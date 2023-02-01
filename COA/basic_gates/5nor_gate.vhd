-- 5. Write down the VHDL program of three input NOR gate with data flow model.

library IEEE;
use IEEE.std_logic_1164.all;

entity norgate is
    port(
        A:in std_logic; 
        B:in std_logic;
        C:in std_logic; 
        Y:out std_logic);
end norgate;

architecture norlogic of norgate is
begin
    Y<=not(A or B or C);
end norlogic;
