//CSC470 HW1
//Kimberly Modeste
#include <GL/glut.h>
#include <math.h>
#include <time.h>       

class GlintPoint {
public:
	int x = 1;
	int y = 1;
};

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //Set display color to white
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640.0, 0, 580.0);

}

void basicHouse(
	GlintPoint peak,
	float width, float height,
	float house[], float roof[], float door[], float doorknob[],
	float window[], float chimney[], float grout[]
)
{
	GLubyte moon[] = { 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00,
					0x00, 0x03, 0xc2, 0x1c, 0x00, 0x00,
					0x02, 0x40, 0x30, 0x43, 0x00, 0xc0,
					0x08, 0x08, 0x44, 0x49, 0x20, 0x90,
					0x08, 0x08, 0x53, 0x54, 0xc8, 0x28,
					0x08, 0x08, 0x54, 0x54, 0x28, 0x28,
					0x08, 0x08, 0x53, 0x49, 0xc8, 0x90,
					0x04, 0x02, 0x44, 0x33, 0x20, 0xc0,
					0x03, 0x00, 0x18, 0xc4, 0x00, 0x00,
					0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
	};

	//House color
	glBegin(GL_POLYGON);
	glColor3fv(grout);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-30 * width) + peak.x, (-20 * height) + peak.y);
	glEnd();
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(moon);
	glBegin(GL_POLYGON);
	glColor3fv(house);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-30 * width) + peak.x, (-20 * height) + peak.y);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);
	//House line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-30 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glEnd();

	//roof fill
	glBegin(GL_POLYGON);
	glColor3fv(roof);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((0 * width) + peak.x, (60 * height) + peak.y);
	glColor3fv(roof);
	glVertex2i((30 * width) + peak.x, (30 * height) + peak.y);
	glEnd();
	//roof strip
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((0 * width) + peak.x, (60 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glEnd();

	//door Fill
	glBegin(GL_POLYGON);
	glColor3fv(door);
	glVertex2i((-20 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (10 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (10 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (-20 * height) + peak.y);
	glEnd();
	//door line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-20 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (10 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (10 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (-20 * height) + peak.y);
	glEnd();

	//window fill
	glBegin(GL_POLYGON);
	glColor3f(0.29, 0.26, 0.22);
	glVertex2i((10 * width) + peak.x, (15 * height) + peak.y);
	glVertex2i((20 * width) + peak.x, (15 * height) + peak.y);
	glColor3fv(window);
	glVertex2i((20 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((10 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((10 * width) + peak.x, (15 * height) + peak.y);
	glEnd();
	//window line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((10 * width) + peak.x, (15 * height) + peak.y);
	glVertex2i((20 * width) + peak.x, (15 * height) + peak.y);
	glVertex2i((20 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((10 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((10 * width) + peak.x, (15 * height) + peak.y);
	glVertex2i((15 * width) + peak.x, (15 * height) + peak.y);
	glVertex2i((15 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((20 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((20 * width) + peak.x, (10 * height) + peak.y);
	glVertex2i((10 * width) + peak.x, (10 * height) + peak.y);
	glEnd();

	//chimney fill
	glBegin(GL_POLYGON);
	glColor3fv(chimney);
	glVertex2i((-20 * width) + peak.x, (40 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (60 * height) + peak.y);
	glVertex2i((-10 * width) + peak.x, (60 * height) + peak.y);
	glColor3fv(chimney);
	glVertex2i((-10 * width) + peak.x, (50 * height) + peak.y);
	glEnd();
	//chimney line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-20 * width) + peak.x, (40 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (60 * height) + peak.y);
	glVertex2i((-10 * width) + peak.x, (60 * height) + peak.y);
	glVertex2i((-10 * width) + peak.x, (50 * height) + peak.y);
	glEnd();

	//doorknob Fill
	glBegin(GL_POLYGON);
	glColor3fv(doorknob);
	glVertex2i((-18 * width) + peak.x, (-7 * height) + peak.y);
	glVertex2i((-18 * width) + peak.x, (-5 * height) + peak.y);
	glVertex2i((-16 * width) + peak.x, (-5 * height) + peak.y);
	glVertex2i((-16 * width) + peak.x, (-7 * height) + peak.y);
	glEnd();
	//doorknob line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-18 * width) + peak.x, (-7 * height) + peak.y);
	glVertex2i((-18 * width) + peak.x, (-5 * height) + peak.y);
	glVertex2i((-16 * width) + peak.x, (-5 * height) + peak.y);
	glVertex2i((-16 * width) + peak.x, (-7 * height) + peak.y);
	glVertex2i((-18 * width) + peak.x, (-7 * height) + peak.y);
	glEnd();
}


void shapeshiftingHouse(
	GlintPoint peak,
	float width, float height,
	float house[], float roof[], float door[], float doorknob[],
	float window[], float chimney[], float grout[]
)
{
	GLubyte brick[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
		0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
		0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
		0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
		0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
		0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
		0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
		0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
		0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
		0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
		0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC
	};

	//House color
	glBegin(GL_POLYGON);
	glColor3fv(grout);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-30 * width) + peak.x, (-20 * height) + peak.y);
	glEnd();
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(brick);
	glBegin(GL_POLYGON);
	glColor3fv(house);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-30 * width) + peak.x, (-20 * height) + peak.y);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);
	//House line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-30 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glEnd();

	//roof fill
	glBegin(GL_POLYGON);
	glColor3fv(roof);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glColor3f(0.95, 0.59, 0.54);
	glVertex2i((0 * width) + peak.x, (60 * height) + peak.y);
	glColor3fv(roof);
	glVertex2i((30 * width) + peak.x, (30 * height) + peak.y);
	glEnd();
	//roof strip
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((0 * width) + peak.x, (60 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (30 * height) + peak.y);
	glVertex2i((-30 * width) + peak.x, (30 * height) + peak.y);
	glEnd();

	//door Fill
	glBegin(GL_POLYGON);
	glColor3fv(door);
	glVertex2i((-20 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (10 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (10 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (-20 * height) + peak.y);
	glEnd();
	//door line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-20 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (10 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (10 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (-20 * height) + peak.y);
	glEnd();

	//window fill
	glBegin(GL_POLYGON);
	glColor3f(0.29, 0.26, 0.22);
	glVertex2i((10 * width) + peak.x, (15 * height) + peak.y);
	glVertex2i((20 * width) + peak.x, (15 * height) + peak.y);
	glColor3fv(window);
	glVertex2i((20 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((10 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((10 * width) + peak.x, (15 * height) + peak.y);
	glEnd();
	//window line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((10 * width) + peak.x, (15 * height) + peak.y);
	glVertex2i((20 * width) + peak.x, (15 * height) + peak.y);
	glVertex2i((20 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((10 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((10 * width) + peak.x, (15 * height) + peak.y);
	glVertex2i((15 * width) + peak.x, (15 * height) + peak.y);
	glVertex2i((15 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((20 * width) + peak.x, (5 * height) + peak.y);
	glVertex2i((20 * width) + peak.x, (10 * height) + peak.y);
	glVertex2i((10 * width) + peak.x, (10 * height) + peak.y);
	glEnd();

	//chimney fill
	glBegin(GL_POLYGON);
	glColor3fv(chimney);
	glVertex2i((-20 * width) + peak.x, (40 * height) + peak.y);
	glColor3f(0.86, 0.68, 0.83);
	glVertex2i((-20 * width) + peak.x, (60 * height) + peak.y);
	glVertex2i((-10 * width) + peak.x, (60 * height) + peak.y);
	glColor3fv(chimney);
	glVertex2i((-10 * width) + peak.x, (50 * height) + peak.y);
	glEnd();
	//chimney line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-20 * width) + peak.x, (40 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (60 * height) + peak.y);
	glVertex2i((-10 * width) + peak.x, (60 * height) + peak.y);
	glVertex2i((-10 * width) + peak.x, (50 * height) + peak.y);
	glEnd();

	//doorknob Fill
	glBegin(GL_POLYGON);
	glColor3fv(doorknob);
	glVertex2i((-18 * width) + peak.x, (-7 * height) + peak.y);
	glVertex2i((-18 * width) + peak.x, (-5 * height) + peak.y);
	glVertex2i((-16 * width) + peak.x, (-5 * height) + peak.y);
	glVertex2i((-16 * width) + peak.x, (-7 * height) + peak.y);
	glEnd();
	//doorknob line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-18 * width) + peak.x, (-7 * height) + peak.y);
	glVertex2i((-18 * width) + peak.x, (-5 * height) + peak.y);
	glVertex2i((-16 * width) + peak.x, (-5 * height) + peak.y);
	glVertex2i((-16 * width) + peak.x, (-7 * height) + peak.y);
	glVertex2i((-18 * width) + peak.x, (-7 * height) + peak.y);
	glEnd();

	//front yard L
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.69, 0.39);
	glVertex2i((-40 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (-100 * height) + peak.y);
	glVertex2i((-40 * width) + peak.x, (-100 * height) + peak.y);
	glEnd();
	//front yard L line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-40 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((-20 * width) + peak.x, (-100 * height) + peak.y);
	glVertex2i((-40 * width) + peak.x, (-100 * height) + peak.y);
	glVertex2i((-40 * width) + peak.x, (-20 * height) + peak.y);
	glEnd();
	//front yard R
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.69, 0.39);
	glVertex2i((-7 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (-50 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (-50 * height) + peak.y);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i((-7 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (-20 * height) + peak.y);
	glVertex2i((30 * width) + peak.x, (-50 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (-50 * height) + peak.y);
	glVertex2i((-7 * width) + peak.x, (-20 * height) + peak.y);
	glEnd();
}

void tree(GlintPoint peak) {

	GLubyte bark[] = { 0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,
						0xAA, 0xAA, 0xAA,0xAA, 0xAA, 0xAA, 0xAA,0xAA,

	};

	//bark color
	glBegin(GL_POLYGON);
	glColor3f(0.67, 0.47, 0.27);
	glVertex2i(-5 + peak.x, 35 + peak.y);
	glVertex2i(5 + peak.x, 35 + peak.y);
	glVertex2i(5 + peak.x, -5 + peak.y);
	glVertex2i(-5 + peak.x, -5 + peak.y);
	glEnd();
	//bark texture
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(bark);
	glBegin(GL_POLYGON);
	glColor3f(0.45, 0.31, 0.18);
	glVertex2i(-5 + peak.x, 35 + peak.y);
	glVertex2i(5 + peak.x, 35 + peak.y);
	glVertex2i(5 + peak.x, -5 + peak.y);
	glVertex2i(-5 + peak.x, -5 + peak.y);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);
	//bark line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(-5 + peak.x, 35 + peak.y);
	glVertex2i(5 + peak.x, 35 + peak.y);
	glVertex2i(5 + peak.x, -5 + peak.y);
	glVertex2i(-5 + peak.x, -5 + peak.y);
	glVertex2i(-5 + peak.x, 35 + peak.y);
	glEnd();
	//leaves
	glBegin(GL_POLYGON);
	glColor3f(0.70, 0.70, 0.39); //green
	glVertex2i(-10 + peak.x, 35 + peak.y);
	glVertex2i(-20 + peak.x, 45 + peak.y);
	glVertex2i(-20 + peak.x, 55 + peak.y);

	glColor3f(0.95, 0.59, 0.54); //pink
	glVertex2i(-10 + peak.x, 65 + peak.y);
	glVertex2i(10 + peak.x, 65 + peak.y);

	glColor3f(0.70, 0.70, 0.39); //green
	glVertex2i(20 + peak.x, 55 + peak.y);
	glVertex2i(20 + peak.x, 45 + peak.y);
	glVertex2i(10 + peak.x, 35 + peak.y);
	glEnd();
	//leaves line
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(-10 + peak.x, 35 + peak.y);
	glVertex2i(-20 + peak.x, 45 + peak.y);
	glVertex2i(-20 + peak.x, 55 + peak.y);
	glVertex2i(-10 + peak.x, 65 + peak.y);
	glVertex2i(10 + peak.x, 65 + peak.y);
	glVertex2i(20 + peak.x, 55 + peak.y);
	glVertex2i(20 + peak.x, 45 + peak.y);
	glVertex2i(10 + peak.x, 35 + peak.y);
	glVertex2i(-10 + peak.x, 35 + peak.y);
	glEnd();

}

void display() {
	GlintPoint p;
	p.x = 200;
	p.y = 300;
	int width = 1;
	int height = 1;
	float house[] = { 0.94, 0.89, 0.80 };
	float roof[] = { 0.54, 0.67, 0.51 };
	float door[] = { 0.39, 0.52, 0.33 };
	float doorknob[] = { 0.89, 0.7, 0.7 };
	float window[] = { 1.0, 0.93, 0.89 }; //float window[] = { 0.29, 0.26, 0.22 };
	float chimney[] = { 0.6, 0.6, 0.6 };
	float grout[] = { 0.83, 0.77, 0.66 };

	//Sky line
	glBegin(GL_POLYGON);
	glColor3f(0.56, 0.54, 1.0);
	glVertex2i(0, 580);
	glVertex2i(640, 580);
	glColor3f(0.93, 0.39, 0.39);
	glVertex2i(640, 300);
	glVertex2i(0, 300);
	glEnd();


	//stars
	int x, y;
	srand(time(0));
	for (int j = 0; j < 2; j++)
	{
		if (j == 0)
		{
			glPointSize(1.5);
		}
		else
		{
			glPointSize(1.0);
		}

		glBegin(GL_POINTS);
		glColor3f(0.84, 0.73, 0.87);
		for (int i = 0; i < 20; i++) {

			x = rand() % 641;
			y = rand() % 80 + 500;
			glVertex2i(x, y);
		}
		glEnd();
	}


	//grass
	glBegin(GL_POLYGON);
	glColor3f(0.70, 0.70, 0.39);
	glVertex2i(0, 300);
	glVertex2i(640, 300);
	glVertex2i(640, 280);
	glVertex2i(0, 100);
	glEnd();


	//making trees
	for (int i = 0; i < 680; i += 50)
	{
		p.x = i;
		tree(p);
	}
	p.y = 280;
	for (int i = 25; i < 680; i += 50)
	{
		p.x = i;
		tree(p);
	}


	//house sidewalk
	glBegin(GL_POLYGON);
	glColor3f(0.59, 0.47, 0.44);
	glVertex2i(0, 280);
	glVertex2i(640, 280);
	glVertex2i(640, 100);
	glVertex2i(0, 100);
	glEnd();


	//Basils house
	p.x = 30;
	p.y = 300;
	shapeshiftingHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	//2nd house
	p.x = 150;
	width = 2;
	height = 1;
	roof[0] = { 0.90 }; roof[1] = { 0.79 }; roof[2] = { 0.52 };
	house[0] = { 0.94 }; house[1] = { 0.94 }; house[2] = { 0.94 };
	grout[0] = { 0.79 }; grout[1] = { 0.78 }; grout[2] = { 0.74 };
	door[0] = { 0.93 }; door[1] = { 0.74 }; door[2] = { 0.43 };
	shapeshiftingHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	//3rd house
	p.x = 270;
	p.y = 320;
	width = 1;
	height = 2;
	roof[0] = { 0.0 }; roof[1] = { 0.0 }; roof[2] = { 0.0 };
	house[0] = { 0.5 }; house[1] = { 0.5 }; house[2] = { 0.5 };
	grout[0] = { 0.79 }; grout[1] = { 0.78 }; grout[2] = { 0.74 };
	door[0] = { 0.0 }; door[1] = { 0.0 }; door[2] = { 0.0 };
	shapeshiftingHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	//4th house
	p.x = 400;
	p.y = 320;
	width = 2;
	height = 2;
	roof[0] = { 0.52 }; roof[1] = { 0.30 }; roof[2] = { 0.16 };
	house[0] = { 0.90 }; house[1] = { 0.82 }; house[2] = { 0.68 };
	grout[0] = { 0.84 }; grout[1] = { 0.73 }; grout[2] = { 0.55 };
	door[0] = { 0.52 }; door[1] = { 0.11 }; door[2] = { 0.11 };
	shapeshiftingHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	//5th house
	p.x = 550;
	p.y = 300;
	width = 2;
	height = 1;
	roof[0] = { 0.39 }; roof[1] = { 0.56 }; roof[2] = { 0.81 };
	house[0] = { 0.96 }; house[1] = { 0.97 }; house[2] = { 0.96 };
	grout[0] = { 0.86 }; grout[1] = { 0.84 }; grout[2] = { 0.8 };
	door[0] = { 0.45 }; door[1] = { 0.69 }; door[2] = { 0.79 };
	shapeshiftingHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	//side walk
	glBegin(GL_POLYGON);
	glColor3f(0.93, 0.90, 0.84);
	glVertex2i(0, 180);
	glVertex2i(640, 180);
	glVertex2i(640, 100);
	glVertex2i(0, 100);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.89, 0.81, 0.70);
	glVertex2i(0, 120);
	glVertex2i(640, 120);
	glVertex2i(640, 100);
	glVertex2i(0, 100);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(0, 180);
	glVertex2i(640, 180);
	glVertex2i(640, 100);
	glVertex2i(0, 100);
	glVertex2i(0, 180);
	glVertex2i(100, 180);
	glVertex2i(100, 120);
	glVertex2i(0, 120);
	glVertex2i(640, 120);
	glVertex2i(600, 120);
	glVertex2i(600, 180);
	glVertex2i(500, 180);
	glVertex2i(500, 120);
	glVertex2i(400, 120);
	glVertex2i(400, 180);
	glVertex2i(300, 180);
	glVertex2i(300, 120);
	glVertex2i(200, 120);
	glVertex2i(200, 180);
	glEnd();
	//road
	glBegin(GL_POLYGON);
	glColor3f(0.59, 0.47, 0.44);
	glVertex2i(0, 120);
	glVertex2i(640, 120);
	glVertex2i(640, 100);
	glVertex2i(0, 100);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.69, 0.57, 0.54);
	glVertex2i(0, 120);
	glVertex2i(640, 120);
	glVertex2i(640, 100);
	glVertex2i(0, 100);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.59, 0.47, 0.34);
	glVertex2i(0, 100);
	glVertex2i(640, 100);
	glVertex2i(640, 0);
	glVertex2i(0, 0);
	glEnd();

	//streetlines
	glBegin(GL_POLYGON);
	glColor3f(0.93, 0.90, 0.84);
	glVertex2i(10, 100);
	glVertex2i(15, 100);
	glVertex2i(15, 0);
	glVertex2i(10, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.93, 0.90, 0.84);
	glVertex2i(15, 2);
	glVertex2i(640, 2);
	glVertex2i(640, 0);
	glVertex2i(15, 0);
	glEnd();



	glFlush();
}

void basicDisplay() {
	GlintPoint p;
	p.x = 300;
	p.y = 500;
	int width = 1;
	int height = 1;
	float house[] = { 1.0, 0.4, 0.7 };
	float roof[] = { 0.0, 0.0, 0.0 };
	float door[] = { 0.6, 0.6, 0.6 };
	float doorknob[] = { 0.0, 0.0, 0.0 };
	float window[] = { 0.29, 0.26, 0.22 };
	float chimney[] = { 0.6, 0.6, 0.6 };
	float grout[] = { 1.0, 0.0, 0.0 };

	//grass
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(0, 580);
	glVertex2i(640, 580);
	glVertex2i(640, 200);
	glVertex2i(0, 200);
	glEnd();
	//lane
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.4, 0.12);
	glVertex2i(0, 400);
	glVertex2i(640, 400);
	glVertex2i(640, 300);
	glVertex2i(0, 300);
	glEnd();
	//stream
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(0, 200);
	glVertex2i(640, 200);
	glVertex2i(640, 0);
	glVertex2i(0, 0);
	glEnd();


	basicHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	p.x = 200;
	p.y = 300;
	basicHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);


	p.x = 100;
	p.y = 450;
	basicHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	p.x = 400;
	p.y = 250;
	basicHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	p.x = 500;
	p.y = 450;
	basicHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	p.x = 550;
	p.y = 240;
	basicHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	p.x = 50;
	p.y = 280;
	basicHouse(p, width, height, house, roof, door, doorknob, window, chimney, grout);

	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); //initialize GLut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 100); //should be center
	glutInitWindowSize(800, 600); //set window width and height
	glutCreateWindow("Basil Street Drawing"); //Title
	myInit();
	glClear(GL_COLOR_BUFFER_BIT);

	//UNCOMMENT THIS FOR BASIC
	glutDisplayFunc(basicDisplay);

	//UNCOMMENT FOR CREATIVE
	//glutDisplayFunc(display);
	
	glFlush();
	glutMainLoop();

}