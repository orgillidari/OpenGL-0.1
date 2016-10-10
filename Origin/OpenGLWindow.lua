function Init()
	glClearColor(0.1, 0.2, 0.3, 1.0);
end

local angle = 0;

function Update()
	glBegin(0x0007);
	glColor3b(100, 100, 0);
	glVertex3f(-10.0, -2.0,10.0);
	glVertex3f(10.0, -2.0, 10.0);
	glVertex3f(10.0, -2.0, -10.0);
	glVertex3f(-10.0, -2.0, -10.0);
	glEnd();

	glColor4ub(200, 0, 0, 255);
	glBegin(0x0004);
	glVertex3f(-1, 0, 0.0);
	glVertex3f(1, 0, 0.0);
	glVertex3f(0, 1, 0.0);
	glEnd();
end

function Destroy()

end