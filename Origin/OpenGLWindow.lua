function Init()
	glClearColor(0.1, 0.2, 0.3, 1.0);
end

function Update()
	glClear(0x00004000, 0x00000100);
	glMatrixMode(0x1701);
	glLoadIdentity();
	gluPerspective(45.0, 1280 / 800, 0.1, 1000.0);

	glMatrixMode(0x1700);
	glLoadIdentity();

	glColor4ub(200, 0, 0, 255);
	glBegin(0x0004);
	glVertex3f(-1, 0, -10.0);
	glVertex3f(1, 0, -10.0);
	glVertex3f(0, 1, -10.0);
	glEnd();
end

function Destory()

end