--diagram.ID: $t{diagram.ID}  ooaofooa_ID: $t{diagram.ooaofooa_ID}  ooaofooa_path: ${diagram.path}
INSERT INTO GD_MD
	VALUES ($t{diagram.ID}, 
	8, -- Model_Type
	$t{diagram.ooaofooa_ID},  -- the id of the ooaofooa element for ISM this is SM_SM.SM_ID
	40, -- OOA_TYPE
	0,
	0,
	1,
	1,
	1,
	12,
	1,   -- grid_on_flag
	0,   -- x_coordinate
	0,   -- y_coordinate
	0,   -- width     
	0,   -- height
	0, 
	'4.1.17',    -- This is the persistence version ("4.1.17" right now). This is set only if widgets are present. It is empty if there are no widgets
	'${diagram.path}');
INSERT INTO DIM_DIA                                     
	VALUES ($t{diagram.ID},
	'',
	1.000000,  -- zoom level
	4000.000000,  -- viewport_x_coordinate - I do not see how this is used. Changes to not seem to do anything
	3000.000000,  -- viewport_y_coordinate - I do not see how this is used. Changes to not seem to do anything
	0);  -- null ID
