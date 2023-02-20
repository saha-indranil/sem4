-- 1. write down the VHDL program NOT with data flow model.

library IEEE;
use IEEE.std_logic_1164.all;

entity notgate is
    port(
        A:in std_logic; 
        Y:out std_logic);
end notgate;

architecture notlogic of notgate is
begin
    Y<=NOT(A);
end notlogic;