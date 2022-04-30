--Isaac's Final Project ERG3083 
--VHDL Top Level Entity

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
USE IEEE.std_logic_arith.ALL;
USE IEEE.std_logic_signed.ALL;

entity signalTest is
	port
	(
		vector_in : in std_logic_vector(5 DOWNTO 0);
		vector_out : out std_logic_vector(5 DOWNTO 0)
	);
end signalTest;


architecture arc of signalTest is


begin
	
	vector_out <= vector_in;
	
end arc;