--Isaac's Final Project ERG3083 
--VHDL Top Level Entity


LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
USE IEEE.std_logic_arith.ALL;
USE IEEE.std_logic_signed.ALL;

entity distance2note is
	port
	(
		current_distance : in std_logic_vector(5 DOWNTO 0);
		clock : in std_logic;
		
		note : out std_logic_vector(4 DOWNTO 0)
	);
end distance2note;

architecture arc of distance2note is
	
begin
	process(current_distance)
		variable ratio : integer := 3;
		variable distance_int : integer;
	begin
		distance_int := conv_integer(current_distance);
		
		for I in 0 to 12 loop
			if (distance_int > ( I*ratio ) and distance_int < ( ( I + 1) *ratio) ) then
				--use variable inside loop
				note <= conv_std_logic_vector(I, note'length);
			end if;
		end loop;
	end process;
end;
