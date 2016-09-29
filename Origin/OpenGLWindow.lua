function Init()
	glClearColor(0.1, 0.2, 0.3, 1.0);
end

function Update()
	glColor4ub(60, 60, 60, 255);
	glBegin(0x0007);
	glVertex3f(-5.0, -1.0, 5.0);
	glVertex3f(5.0, -1.0, 5.0);
	glVertex3f(5.0, -1.0, -5.0);
	glVertex3f(-5.0, -1.0, -5.0);
	glEnd();

	glColor4ub(200, 0, 0, 255);
	glBegin(0x0004);
	glVertex3f(-1, 0, -10.0);
	glVertex3f(1, 0, -10.0);
	glVertex3f(0, 1, -10.0);
	glEnd();
end

function Destroy()

end