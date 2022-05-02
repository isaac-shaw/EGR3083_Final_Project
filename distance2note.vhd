
   
--Isaac's Final Project ERG3083 
--VHDL logic to find out what note to play based on distance


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
		variable ratio : integer := 4;
        variable counter : integer;
		variable distance_int : integer;
		variable note_int : integer;
		
	begin
		distance_int := conv_integer(current_distance);
        
        if( distance_int > (14*ratio) ) then
        	note_int := 0;
        else
        	counter := 0;
            
        	for i in 1 to 13 loop
            	if(distance_int > (counter*ratio) and distance_int < (ratio * (counter+1))) then
                	note_int := 0 + counter;
           		end if;
                counter := counter + 1;
            end loop;
        end if;
		
		note <= conv_std_logic_vector(note_int, note'length);
		
	end process;
end;
