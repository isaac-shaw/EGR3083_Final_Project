--Isaac's Final Project ERG3083 
--VHDL Top Level Entity

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
USE IEEE.std_logic_arith.ALL;
USE IEEE.std_logic_signed.ALL;

entity bit2vector is
	port
	(
		in0 : in std_logic;
		in1 : in std_logic;
		in2 : in std_logic;
		in3 : in std_logic;
		in4 : in std_logic;
		in5 : in std_logic;
		
		clock : in std_logic;
		
		vector_out : out std_logic_vector(5 DOWNTO 0)
	);
end bit2vector;

architecture arc of bit2vector is


begin
	process(in5)
		begin			
			vector_out(0) <= in0;
			vector_out(1) <= in1;
			vector_out(2) <= in2;
			vector_out(3) <= in3;
			vector_out(4) <= in4;
			if(in5 = 'U') then
				vector_out(5) <= '0';
			else
				vector_out(5) <= in5;
			end if;
		end process;
	end;