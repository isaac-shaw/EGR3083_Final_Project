--Isaac's Final Project ERG3083 
--VHDL Top Level Entity

library ieee;
use ieee.std_logic_1164.all;
library altera;
use altera.altera_syn_attributes.all;

entity de0_nano_soc_baseline is
	port
	(
-- {ALTERA_IO_BEGIN} DO NOT REMOVE THIS LINE!
		CLOCK_50 : in std_logic;
		
		LED : out std_logic_vector(7 downto 0);
		
		GPIO_1 : in std_logic_vector(35 downto 0)

		
-- {ALTERA_IO_END} DO NOT REMOVE THIS LINE!

	);

-- {ALTERA_ATTRIBUTE_BEGIN} DO NOT REMOVE THIS LINE!
-- {ALTERA_ATTRIBUTE_END} DO NOT REMOVE THIS LINE!
end de0_nano_soc_baseline;

architecture ppl_type of de0_nano_soc_baseline is

-- {ALTERA_COMPONENTS_BEGIN} DO NOT REMOVE THIS LINE!
-- {ALTERA_COMPONENTS_END} DO NOT REMOVE THIS LINE!
	
	signal pass_through_1 : std_logic_vector(5 downto 0);
	signal pass_through_2 : std_logic_vector(4 downto 0);

	component distance2note is
	port (
		current_distance : in std_logic_vector(5 DOWNTO 0);
		clock : in std_logic;
		
		note : out std_logic_vector(4 DOWNTO 0)
	);
	end component;
	
	component bit2vector IS
   port(
		in0 : in std_logic;
		in1 : in std_logic;
		in2 : in std_logic;
		in3 : in std_logic;
		in4 : in std_logic;
		in5 : in std_logic;
		
		clock : in std_logic;
		
		vector_out : out std_logic_vector(5 DOWNTO 0)
	);
	 end component;
	 
	 component signalTest is
	port
	(
		vector_in : in std_logic_vector(5 DOWNTO 0);
		
		vector_out : out std_logic_vector(5 DOWNTO 0)
	);
end component;
	
	signal clock1Hz: std_logic;
	signal lights : std_logic_vector(2 downto 0);
	
begin
-- {ALTERA_INSTANTIATION_BEGIN} DO NOT REMOVE THIS LINE!
-- {ALTERA_INSTANTIATION_END} DO NOT REMOVE THIS LINE!
	
	--VECTORIZE:	bit2vector port map(Arduino_IO0, Arduino_IO1, Arduino_IO2, Arduino_IO3, Arduino_IO4, Arduino_IO5, CLOCK_50, pass_through_1);
	--MANAGER: 	distance2note port map(pass_through_1, CLOCK_50, pass_through_2);
	tester: signalTest port map(GPIO_1(5 downto 0), LED(5 downto 0));
	
	--Arduino_IO9 	<= pass_through_2(0);
	--Arduino_IO10	<= pass_through_2(1);
	--Arduino_IO11	<= pass_through_2(2);
	--Arduino_IO12	<= pass_through_2(3);
	--Arduino_IO13	<= pass_through_2(4);
	
	--LED(5 downto 0) <= pass_through_1(5 downto 0);
	
	end;