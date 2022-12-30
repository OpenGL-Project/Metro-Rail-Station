/*///////////////////////////////////////////
1) MOHAMMAD NAIMUL HAQUE   SEC: H  21-44387-1

2) MD. RAKIBUL HASAN       SEC:H   21-44418-1

3) TANBIR YOUSUF           SEC:H   21-44394-1

4) MD. AZMAINUL HAQUE      SEC:H   20-43893-2

5) SHAFIUL ISLAM MAZUMDER  SEC:H   19-41370-3

Compiled by: TANBIR YOUSUF
*////////////////////////////////////////////

#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#define PI    3.141516
#include<math.h>

GLint time = 1; //1 = Day, 2 = Evening, 3 = Nigth
GLboolean light = false;
GLfloat position = 0.0f;
GLfloat busposition = 0.0f;
GLfloat carposition = 0.0f;
GLfloat carposition2 = -0.99f;
GLfloat carSmokeposition = 0.0f;
GLfloat RoadHumanRightmostPosition = 0.0f;
GLfloat RoadHumanNearEscPosition = 0.0f;
GLfloat EscHumanPositionX = 0.0f;
GLfloat EscHumanPositionY = 0.0f;
GLfloat speed = 0.050f;
GLfloat busspeed = 0.02f;
GLfloat carspeed = 0.02f;
GLfloat carSmokeSpeed = 0.008f;
GLfloat RoadHumanRightmostSpeed = 0.006f;
GLfloat RoadHumanNearEscSpeed = 0.002f;
GLfloat EscHumanSpeedX = 0.004f;
GLfloat EscHumanSpeedY = 0.0076f;
GLfloat positions = 0.0f;
GLfloat speeds = 0.04f;
GLfloat positionb = 0.0f;
GLfloat speedb = 0.001f;
GLfloat playerspeed = 0.006f;
GLfloat playerpos = 0.05f;
GLfloat footballx = 0.0f;
GLfloat footbally = 0.0f;
GLfloat footballs = 0.02f;
GLfloat fanrotate = 0.0f;
GLfloat slrortate = 0.0f, slfactor = 3.0f; //Sky Light on BD5

void update(int value)
{
    ///yacht
    if (positionb < -2.0)
        positionb = 2.0f;

    positionb -= speedb;

    ///sun
    if(positions <-2.0)
        positions = 2.0f;

    positions -= speeds;

    ///train
    if (position < -2.0)
        position = 2.0f;

    position -= speed;

    ///bus
    if (busposition < -1.4)

        busposition = 1.4f;

    if ( busposition < 0.105-0.5 && busposition >-0.0-0.5 )
        {
            busposition -= 0.001;
        }

     else
        busposition -= busspeed;
    ///car 1
    if (carposition > 1.4)
        carposition = -1.4f;
    carposition += carspeed;

    ///Car 2
    if (carposition2 > 1.4)
        carposition2 = -1.4f;

    carposition2 += carspeed;

    ///car smoke
    if (carSmokeposition < -0.066875f)
        carSmokeposition = 0.02f;

    carSmokeposition -= carSmokeSpeed;

    ///roadhumanRightmost
    if (RoadHumanRightmostPosition < -0.41)
        RoadHumanRightmostPosition = .07f;

    RoadHumanRightmostPosition -= RoadHumanRightmostSpeed;
    ///roadhumanNearEsc
    if (RoadHumanNearEscPosition < -0.55)
        RoadHumanNearEscPosition = 0.0f;

    RoadHumanNearEscPosition -= RoadHumanNearEscSpeed;
    ///eschuman
    if (EscHumanPositionX < -0.5)
        EscHumanPositionX  = -0.3f;

    EscHumanPositionX  -= EscHumanSpeedX;
    if (EscHumanPositionY < 0.55f)
    {
        EscHumanPositionY  += EscHumanSpeedY;
    }
    ///players
    if(playerpos > 0.05f || playerpos < -0.05)
    {
        playerspeed *= -1;
    }
    playerpos += playerspeed;

    ///Football
    if(footballx > 0.4f || footballx < 0.0f)
    {
        footballs *= -1;
    }
    footballx += footballs;


    ///Fan
    if(fanrotate >= 360.0)
    {
        fanrotate = 0.0f;
    }
    fanrotate += 5.0f;

    ///Sky Light
    if(slrortate >= 60 || slrortate <=- 60)
    {
        slfactor *= -1.0f;
    }
    slrortate += slfactor;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

////////Shapes and objects/////////

void sun() //NAIMUL HAQUE
{
     glPushMatrix();
    glTranslatef(0.0f,-positions, 0.0f);
    int i;
///....................................................................................LOW OPACITY circle-2
            GLfloat p1m1=-0.80f; GLfloat q1m1= 0.32f; GLfloat r1m1 = 0.12375f; GLfloat r2m1= 0.22f;
    int tringle2m1=40;
    GLfloat tp2m1 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor4ub (251,247,208,50);
    glVertex2f (p1m1,q1m1);
    for(i= 0;i<=tringle2m1; i++)
    {
        glVertex2f (
                    p1m1+(r1m1*cos(i*tp2m1/tringle2m1)),
                    q1m1+(r2m1*sin(i*tp2m1/tringle2m1))
                    );
    }
    glEnd ();
///....................................................................................Intence circle-3
    GLfloat p1m2=-0.80f; GLfloat q1m2= 0.32f; GLfloat r1m2 = 0.1125f; GLfloat r2m2= 0.20f;
    int tringle2m2=40;
    GLfloat tp2m2 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,201,55);
    glVertex2f (p1m2,q1m2);
    for(i= 0;i<=tringle2m2; i++)
    {
        glVertex2f (
                    p1m2+(r1m2*cos(i*tp2m2/tringle2m2)),
                    q1m2+(r2m2*sin(i*tp2m2/tringle2m2))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void moon() //NAIMUL HAQUE
{
    glPushMatrix();
    glTranslatef(0.0f,-positions/4, 0.0f);
    int i;
///....................................................................................LOW OPACITY circle-2
            GLfloat p1m1=-0.80f; GLfloat q1m1= 0.32f; GLfloat r1m1 = 0.12375f; GLfloat r2m1= 0.22f;
    int tringle2m1=40;
    GLfloat tp2m1 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor4ub (251,247,208,100);
    glVertex2f (p1m1,q1m1);
    for(i= 0;i<=tringle2m1; i++)
    {
        glVertex2f (
                    p1m1+(r1m1*cos(i*tp2m1/tringle2m1)),
                    q1m1+(r2m1*sin(i*tp2m1/tringle2m1))
                    );
    }
    glEnd ();
///....................................................................................Intence circle-3
    GLfloat p1m2=-0.80f; GLfloat q1m2= 0.32f; GLfloat r1m2 = 0.1125f; GLfloat r2m2= 0.20f;
    int tringle2m2=40;
    GLfloat tp2m2 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (249,242,183);
    glVertex2f (p1m2,q1m2);
    for(i= 0;i<=tringle2m2; i++)
    {
        glVertex2f (
                    p1m2+(r1m2*cos(i*tp2m2/tringle2m2)),
                    q1m2+(r2m2*sin(i*tp2m2/tringle2m2))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void cloud() ///NAIMUL HAQUE.................................................................
{
    //Circle define
    int i;
    //Cloud 1 Left///////////////////////////////////////////////
     GLfloat p1=-0.15f; GLfloat q1= 0.7f; GLfloat r1 = 0.1f;
    int tringle2=40;

    GLfloat tp2 =3.0f * PI ;

    GLfloat p2=-0.35f; GLfloat q2= 0.7f; GLfloat r2 = 0.15f;
    int tringle3=40;

    GLfloat tp3 =3.0f * PI ;

     GLfloat p3=-0.55f; GLfloat q3= 0.7f; GLfloat r3 = 0.1f;
    int tringle4=40;

    GLfloat tp4 =3.0f * PI ;
    //CLOUD.............................................................
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 232,232,232);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );

    }
    glEnd ();

     glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 232,232,232);
    glVertex2f (p2,q2);
    for(i= 0;i<=tringle3; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp3/tringle3)),
                    q2+(r2*sin(i*tp3/tringle3))
                    );

    }
    glEnd ();

     glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 232,232,232);
    glVertex2f (p3,q3);
    for(i= 0;i<=tringle4; i++)
    {
        glVertex2f (
                    p3+(r3*cos(i*tp4/tringle4)),
                    q3+(r3*sin(i*tp4/tringle4))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void yacht() //NAIMUL HAQUE
{
    glPushMatrix();
    glTranslatef(-positionb,-positionb/5, 0.0f);
    glBegin(GL_POLYGON);                  ///base grey
    glColor3ub(223, 223, 223);
    glVertex2f(-0.91f,0.02f);
    glVertex2f(-0.93f,0.087f);
    glVertex2f(-0.50f,0.15f);
    glVertex2f(-0.53f,0.1f);
    glEnd();

    glBegin(GL_POLYGON);                  //base 2 narrow black
    glColor3ub(0, 0, 0);
    glVertex2f(-0.93f,0.087f);
    glVertex2f(-0.93f,0.14f);
    glVertex2f(-0.49f,0.17f);
    glVertex2f(-0.50f,0.15f);
    glEnd();

    glLineWidth(1.0); ///base mid line
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.92f,0.085f);
    glVertex2f(-0.57f,0.13f);
    glEnd();
///..............................Yacht 1st row windows
    glBegin(GL_POLYGON);                  //3/1 window 1st round
    glColor3ub(0, 0, 253);
    glVertex2f(-0.92f,0.11f);
    glVertex2f(-0.91f,0.17f);
    glVertex2f(-0.70f,0.20f);
    glVertex2f(-0.7f,0.13f);
    glEnd();

    glBegin(GL_POLYGON);                  ///3/2 window 1st round
    glColor3ub(0, 0, 253);
    glVertex2f(-0.71f,0.13f);
    glVertex2f(-0.71f,0.20f);
    glVertex2f(-0.44f,0.25f);
    glVertex2f(-0.49f,0.16f);
    glEnd();

//    glLineWidth(1.0); //small window up of 1st round
//    glBegin(GL_LINES);
//    glColor3ub(0,0,0);
//    glVertex2f(-0.873958f,0.183333f);
//    glVertex2f(-0.848958f,0.227778f);
//    glEnd();
////
    glBegin(GL_POLYGON);                  ///2nd windows 1/4
    glColor3ub(223, 223, 223);
    glVertex2f(-0.85f,0.18f);
    glVertex2f(-0.84f,0.22f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.71f,0.197f);
    glEnd();

    glBegin(GL_POLYGON);                  ///2nd windows 2/4 triangle
    glColor3ub(253, 253, 253);
    glVertex2f(-0.71f,0.197f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.67f,0.198f);
    glEnd();

    glBegin(GL_POLYGON);                  ///2nd windows 3/4 trapezoid
    glColor3ub(253 , 253, 253);
    glVertex2f(-0.695833f,0.211111f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.666667f,0.238889f);
    glVertex2f(-0.67f,0.198f);
    glEnd();

    glBegin(GL_POLYGON);                  ///2nd windows 4/4 trapezoid
    glColor3ub(253,253,253);
    glVertex2f(-0.67f,0.198f);
    glVertex2f(-0.667f,0.238f);
    glVertex2f(-0.53f,0.257f);
    glVertex2f(-0.53f,0.23f);
    glEnd();

///.......................2nd Window separator


    glLineWidth(1.0); //1
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.82f,0.18f);
    glVertex2f(-0.82f,0.225f);
    glEnd();

    glLineWidth(1.0); //1
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.78f,0.19f);
    glVertex2f(-0.78f,0.225f);
    glEnd();

    glLineWidth(1.0); //1
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.76f,0.19f);
    glVertex2f(-0.76f,0.225f);
    glEnd();

///.....................3rd body....
    glBegin(GL_POLYGON);                  ///1ST FROM LEFT  1/4 trapezoid YELLOW
    glColor3ub(182,117,77);
    glVertex2f(-0.908f,0.227f);
    glVertex2f(-0.896f,0.246f);
    glVertex2f(-0.828f,0.255f);
    glVertex2f(-0.832f,0.222f);
    glEnd();

    glBegin(GL_POLYGON);                  ///2nd FROM LEFT  2/4 trapezoid Red
    glColor3ub(255,0,0);
    glVertex2f(-0.832f,0.222f);
    glVertex2f(-0.828f,0.255f);
    glVertex2f(-0.816667f,0.255f);
    glVertex2f(-0.81875f,0.222f);
    glEnd();

    glBegin(GL_POLYGON);                  ///3rd FROM LEFT  3/4 trapezoid Red
    glColor3ub(255,0,0);
    glVertex2f(-0.81875f,0.222f);
    glVertex2f(-0.816667f,0.255f);
    glVertex2f(-0.559375f,0.285185f);
    glVertex2f(-0.559375f,0.25f);
    glEnd();

    glBegin(GL_POLYGON);                  ///4th FROM LEFT  4/4 trapezoid Red
    glColor3ub(255,0,0);
    glVertex2f(-0.559375f,0.25f);
    glVertex2f(-0.559375f,0.285185f);
    glVertex2f(-0.442708f,0.249f);
    glVertex2f(-0.53125f,0.232f);
    glEnd();
///..........................................................................
  ///Driver cabinet............................

    glBegin(GL_POLYGON);                  ///1st FROM LEFT  1/2 trapezoid Red
    glColor3ub(223,223,223);
    glVertex2f(-0.80625f,0.257f);
    glVertex2f(-0.785417f,0.312963f);
    glVertex2f(-0.660417f,0.324074f);
    glVertex2f(-0.641667f,0.275f);
    glEnd();

///Top...........................................
    glBegin(GL_POLYGON);                  ///1st FROM TOP  1/1 trapezoid grey
    glColor3ub(223,200,223);
    glVertex2f(-0.842708f,0.309259f);
    glVertex2f(-0.828125f,0.331481f);
    glVertex2f(-0.684375f,0.346296f);
    glVertex2f(-0.660417f,0.32f);
    glEnd();
    glPopMatrix();
}


void busstop()
{
     //--------------------------------------------- Bus Stop START
    glBegin(GL_QUADS);                    // back glass
    glColor4ub(100, 149, 237, 100);
    glVertex2f(0.15f, -0.45f);
    glVertex2f(0.15f, -0.30f);
    glVertex2f(-0.05f, -0.30f);
    glVertex2f(-0.05f, -0.45f);
    glEnd();

    glLineWidth(5);                       // back borders - vertical 2
    glBegin(GL_LINES);
	glColor3ub(105,105,105);
	glVertex2f(0.15f, -0.5f);
	glVertex2f(0.15f, -0.30f);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(105,105,105);
	glVertex2f(-0.05f, -0.5f);
	glVertex2f(-0.05f, -0.30f);
	glEnd();

    glBegin(GL_LINES);                // horizontal 2
	glColor3ub(105,105,105);
	glVertex2f(-0.05f, -0.45f);
	glVertex2f(0.15f, -0.45f);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(105,105,105);
	glVertex2f(-0.05f, -0.30f);
	glVertex2f(0.15f, -0.30f);
	glEnd();

    glBegin(GL_LINES);                    // middle 2
	glColor3ub(105,105,105);
	glVertex2f(0.015f, -0.45f);
	glVertex2f(0.015f, -0.30f);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(105,105,105);
	glVertex2f(0.085f, -0.45f);
	glVertex2f(0.085f, -0.30f);
	glEnd();

    glBegin(GL_POLYGON);                  //top cover
    glColor3ub(119, 136, 153);
	glVertex2f(0.153f, -0.30f);
    glVertex2f(0.17f, -0.25);
    glVertex2f(-0.07f, -0.25f);
	glVertex2f(-0.053f, -0.30f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);                    //bench main
	glColor3ub(255,127,80);
	glVertex2f(-0.01f, -0.47f);
	glVertex2f(0.11f, -0.47f);
	glEnd();

    glBegin(GL_LINES);                    //bench back vertical 2 grill
    glColor3ub(255,127,80);
	glVertex2f(0.015f, -0.5f);
	glVertex2f(0.015f, -0.42f);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255,127,80);
	glVertex2f(0.085f, -0.5f);
	glVertex2f(0.085f, -0.42f);
	glEnd();

    glLineWidth(2);                         //bench back horizontal grills
    glBegin(GL_LINES);
	glColor3ub(255,127,80);
	glVertex2f(0.0f, -0.42f);
	glVertex2f(0.10f, -0.42f);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255,127,80);
	glVertex2f(0.0f, -0.43f);
	glVertex2f(0.10f, -0.43f);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255,127,80);
	glVertex2f(0.0f, -0.44f);
	glVertex2f(0.10f, -0.44f);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255,127,80);
	glVertex2f(0.0f, -0.45f);
	glVertex2f(0.10f, -0.45f);
	glEnd();

    glLineWidth(3);                  // bench legs
	glBegin(GL_LINES);
    glColor3ub(255,127,80);
	glVertex2f(0.0f, -0.5f);
	glVertex2f(0.0f, -0.47f);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255,127,80);
	glVertex2f(0.1f, -0.5f);
	glVertex2f(0.1f, -0.47f);
	glEnd();

    glBegin(GL_LINES);                //Bus stop sign
	glColor3ub(119, 136, 153);
	glVertex2f(-0.075f, -0.5f);
	glVertex2f(-0.075f, -0.4f);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2f(-0.06f, -0.4f);
    glVertex2f(-0.06f, -0.35f);
    glVertex2f(-0.09f, -0.35f);
    glVertex2f(-0.09f, -0.4f);
    glEnd();
}

void goalpost()
{
    glBegin(GL_QUADS);
    glColor3ub(0,0,0); ////////GOAL POST
    glVertex2f(-0.44f, -0.94f);
    glVertex2f(-0.44f, -0.78f);
    glVertex2f(-0.39f,-0.75f);
    glVertex2f(-0.39f, -0.91f);
    glEnd();

    glLineWidth(3.5);////////////////////JAL BANANU BY LINE
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.44f,-0.80f);
    glVertex2f(-0.39f, -0.78f);
    glEnd();

    glLineWidth(3.5);////////////////////JAL BANANU BY LINE
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.44f,-0.83f);
    glVertex2f(-0.39f, -0.81f);
    glEnd();

    glLineWidth(3.5);////////////////////JAL BANANU BY LINE
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.44f,-0.86f);
    glVertex2f(-0.39f, -0.84f);
    glEnd();

    glLineWidth(3.5);////////////////////JAL BANANU BY LINE
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.44f,-0.89f);
    glVertex2f(-0.39f, -0.87f);
    glEnd();

    glLineWidth(3.5);////////////////////JAL BANANU BY LINE
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.44f,-0.92f);
    glVertex2f(-0.39f, -0.90f);
    glEnd();


    glLineWidth(3.0);////////////////////PARALLEL LINES FOR JAL
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.43f,-0.936f);
    glVertex2f(-0.425f, -0.77f);
    glEnd();


    glLineWidth(3.0);////////////////////PARALLEL LINES FOR JAL
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.42f,-0.932f);
    glVertex2f(-0.415f, -0.765f);
    glEnd();


    glLineWidth(3.0);////////////////////PARALLEL LINES FOR JAL
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.41f,-0.930f);
    glVertex2f(-0.405f, -0.760f);
    glEnd();
}

void player()
{
    glBegin(GL_QUADS);
    glColor3ub(255,0,0); ////////GROUND PLAYER 1
    glVertex2f(-0.345f, -0.82f);
    glVertex2f(-0.345f, -0.77f);
    glVertex2f(-0.32f,-0.77f);
    glVertex2f(-0.32f, -0.82f);
    glEnd();

    GLfloat p1=-0.332f; GLfloat q1= -0.755f; GLfloat r1 = 0.015f; ////PLAYER 1 HEAD
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,255);
    glVertex2f (p1,q1);
    for(int i= 0;i<=tringle2; i++)
    {
        glVertex2f (
        p1+(r1*cos(i*tp2/tringle2)),
        q1+(r1*sin(i*tp2/tringle2))
        );
    }
    glEnd ();

    glLineWidth(3.5);////////////////////FIRST PLAYER RIGHT LEG
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(-0.325f,-0.84f);
    glVertex2f(-0.325f, -0.82f);
    glEnd();

    glLineWidth(3.5);////////////////////FIRST PLAYER FIRST HAND
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(-0.337f,-0.84f);
    glVertex2f(-0.337f, -0.82f);
    glEnd();

    glLineWidth(3.5);////////////////////FIRST PLAYER FIRST HAND
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(-0.32f,-0.78f);
    glVertex2f(-0.305f, -0.79f);
    glEnd();

    glLineWidth(3.5);////////////////////FIRST PLAYER 2ND HAND
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(-0.32f,-0.80f);
    glVertex2f(-0.310f, -0.81f);
    glEnd();
}

void sky() //NAIMUL HAQUE
{
    glBegin(GL_POLYGON);     ///SKY PART1
    glColor3ub(133,186,228);
    glVertex2f(-1.00f,1.00f);
    glVertex2f(1.00f,1.00f);
    glVertex2f(1.00f,0.765f);
    glVertex2f(-1.00f,0.765f);
    glEnd();

    glBegin(GL_POLYGON);     ///SKY PART2
    glColor3ub(166,204,236);;
    glVertex2f(-1.00f,0.765f);
    glVertex2f(1.00f,0.765f);
    glVertex2f(1.00f,0.635185f);
    glVertex2f(-1.00f,0.635185f);
    glEnd();

    glBegin(GL_POLYGON);     ///SKY PART3
    glColor3ub(190,218,241);
    glVertex2f(-1.00f,0.635185f);
    glVertex2f(1.00f,0.635185f);
    glVertex2f(1.00f,0.468518f);
    glVertex2f(-1.00f,0.468518f);
    glEnd();

    glBegin(GL_POLYGON);     ///SKY PART4
    glColor3ub(208,228,244);
    glVertex2f(-1.00f,0.468518f);
    glVertex2f(1.00f,0.468518f);
    glVertex2f(0.996875f,0.157407f);
    glVertex2f(-0.996875f,0.157407f);
    glEnd();
}

void nightSky() ///NAIMUL HAQUE...................................................................
{
    glBegin(GL_POLYGON);     ///NIGHT SKY PART1
    glColor3ub(117,70,174);
    glVertex2f(-1.00f,1.00f);
    glVertex2f(1.00f,1.00f);
    glVertex2f(1.00f,0.765f);
    glVertex2f(-1.00f,0.765f);
    glEnd();

    glBegin(GL_POLYGON);     ///NIGHT SKY PART2
    glColor3ub(134,89, 189);;
    glVertex2f(-1.00f,0.765f);
    glVertex2f(1.00f,0.765f);
    glVertex2f(1.00f,0.635185f);
    glVertex2f(-1.00f,0.635185f);
    glEnd();

    glBegin(GL_POLYGON);     ///NIGHT SKY PART3
    glColor3ub(160,126,203);
    glVertex2f(-1.00f,0.635185f);
    glVertex2f(1.00f,0.635185f);
    glVertex2f(1.00f,0.468518f);
    glVertex2f(-1.00f,0.468518f);
    glEnd();

    glBegin(GL_POLYGON);     ///NIGHT SKY PART4
    glColor3ub(173,142,210);
    glVertex2f(-1.00f,0.468518f);
    glVertex2f(1.00f,0.468518f);
    glVertex2f(0.996875f,0.157407f);
    glVertex2f(-0.996875f,0.157407f);
    glEnd();
}

void river() //NAIMUL HAQUE
{
    glBegin(GL_POLYGON);
    glColor3ub(54, 107, 151);
    glVertex2f(-1.0f, 0.20f);
    glVertex2f(1.0f, 0.52f);
    glVertex2f(1.0f, 0.16f);
    glVertex2f(-1.0f, -0.65f);
    glEnd();
}

void beach()
{
    glBegin(GL_POLYGON);
    glColor3ub(255, 219, 125);
    glVertex2f(1.0f, 0.16f);
    glVertex2f(-1.0f, -0.65f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();
}

void building5()
{
     glBegin(GL_POLYGON);                  ///NAIMUL HAQUE Building 5
    glColor3ub(223, 223, 223);
    glVertex2f(-0.31f, 0.60f);
    glVertex2f(0.02f, 0.6f);
    glVertex2f(0.03f, -0.60f);
    glVertex2f(-0.31f, -0.60f);
    glEnd();
    if(light)
    {
        glPushMatrix();
        glTranslatef(-0.13f,0.67f,0.0);
        glRotatef(slrortate, 0, 0, 1);
        glTranslatef(+0.13f,-0.67f,0.0);
        glBegin(GL_POLYGON);     ///NIGHT SKY BUILDING 5 TOP LIGHT
        glColor4ub(254,249,199,100);
        glVertex2f(-0.13f,0.67f);
        glVertex2f(-0.03f,1.5f);
        glVertex2f(-0.23f,1.5f);
        glEnd();
        glPopMatrix();
    }

    glBegin(GL_POLYGON);                  ///NAIMUL HAQUE Building 5 Light
    glColor3ub(112,112,112);
    glVertex2f(-0.15f,0.68f);
    glVertex2f(-0.11f,0.68f);
    glVertex2f(-0.11f,0.62f);
    glVertex2f(-0.15f,0.62f);
    glEnd();

    //window 1
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(-0.28f, 0.48f);
    glVertex2f(-0.16f, 0.48f);
    glVertex2f(-0.16f, 0.34f);
    glVertex2f(-0.28f, 0.34f);
    glEnd();

    //window 2
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(-0.14f, 0.48f);
    glVertex2f(-0.02f, 0.48f);
    glVertex2f(-0.02f, 0.34f);
    glVertex2f(-0.14f, 0.34f);
    glEnd();

    //window 3
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(-0.28f, 0.26f);
    glVertex2f(-0.16f, 0.26f);
    glVertex2f(-0.16f, 0.12f);
    glVertex2f(-0.28f, 0.12f);
    glEnd();

    //window 4
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(-0.14f, 0.26f);
    glVertex2f(-0.02f, 0.26f);
    glVertex2f(-0.02f, 0.12f);
    glVertex2f(-0.14f, 0.12f);
    glEnd();

    //window 5
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(-0.28f, 0.04f);
    glVertex2f(-0.16f, 0.04f);
    glVertex2f(-0.16f, -0.10f);
    glVertex2f(-0.28f, -0.10f);
    glEnd();
    //window 6
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(-0.14f, 0.04f);
    glVertex2f(-0.02f, 0.04f);
    glVertex2f(-0.02f, -0.10f);
    glVertex2f(-0.14f, -0.10f);
    glEnd();

    //window 7
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(-0.28f, -0.18f);
    glVertex2f(-0.16f, -0.18f);
    glVertex2f(-0.16f, -0.32f);
    glVertex2f(-0.28f, -0.32f);
    glEnd();

    //window 8
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(-0.14f, -0.18f);
    glVertex2f(-0.02f, -0.18f);
    glVertex2f(-0.02f, -0.32f);
    glVertex2f(-0.14f, -0.32f);
    glEnd();

    //DOOR
    glBegin(GL_POLYGON);
    glColor3ub(89, 29, 0);                 //NAIMUL HAQUE
    glVertex2f(-0.22f, -0.39f);
    glVertex2f(-0.04f, -0.39f);
    glVertex2f(-0.04f, -0.53f);
    glVertex2f(-0.22f, -0.53f);
    glEnd();
}

void building4()
{
        //Building 4 Main body
    glBegin(GL_POLYGON);
    glColor3ub(193, 193, 193);
    glVertex2f(0.13f, 0.66f);
    glVertex2f(0.49f, 0.66f);    //NAIMUL HAQUE
    glVertex2f(0.49f, -0.59f);
    glVertex2f(0.13f, -0.59f);
    glEnd();

    //TOP OF 4..........................
    glBegin(GL_POLYGON);
    glColor3ub(164, 164, 164);
    glVertex2f(-0.32f, 0.65f);  //NAIMUL HAQUE
    glVertex2f(0.05f, 0.65f);
    glVertex2f(0.05f, 0.60f);
    glVertex2f(-0.32f, 0.60f);
    glEnd();

    //Building 4 Top part
    glBegin(GL_POLYGON);
    glColor3ub(193, 193, 193);             //NAIMUL HAQUE
    glVertex2f(0.21f, 0.97f);
    glVertex2f(0.43f, 0.97f);
    glVertex2f(0.43f, 0.66f);
    glVertex2f(0.21f, 0.66f);
    glEnd();

    //windows 1
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.15f, 0.50f);
    glVertex2f(0.26f, 0.50f);
    glVertex2f(0.26f, 0.37f);
    glVertex2f(0.15f, 0.37f);
    glEnd();
    //windows 2
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.30f, 0.50f);
    glVertex2f(0.41f, 0.50f);
    glVertex2f(0.41f, 0.37f);
    glVertex2f(0.30f, 0.37f);
    glEnd();

    //windows 3
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.15f, 0.25f);
    glVertex2f(0.26f, 0.25f);
    glVertex2f(0.26f, 0.12f);
    glVertex2f(0.15f, 0.12f);
    glEnd();
    //windows 4
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.30f, 0.25f);
    glVertex2f(0.41f, 0.25f);
    glVertex2f(0.41f, 0.12f);
    glVertex2f(0.30f, 0.12f);
    glEnd();

    //windows 5
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.26f, 0.0f);
    glVertex2f(0.26f, -0.13f);
    glVertex2f(0.15f, -0.13f);
    glEnd();

    //windows 6
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.30f, 0.0f);
    glVertex2f(0.41f, 0.0f);
    glVertex2f(0.41f, -0.13f);
    glVertex2f(0.30f, -0.13f);
    glEnd();

    //windows 7
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.15f, -0.25f);
    glVertex2f(0.26f, -0.25f);
    glVertex2f(0.26f, -0.38f);
    glVertex2f(0.15f, -0.38f);
    glEnd();

    //windows 8
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.30f, -0.25f);
    glVertex2f(0.41f, -0.25f);
    glVertex2f(0.41f, -0.38f);
    glVertex2f(0.30f, -0.38f);
    glEnd();
}

void building3()
{
    glBegin(GL_POLYGON);                    //NAIMUL HAQUE
    glColor3ub(164, 164, 164);
    glVertex2f(0.40f, 0.56f);
    glVertex2f(0.59f, 0.56f);
    glVertex2f(0.59f, -0.59f);
    glVertex2f(0.40f, -0.59f);
    glEnd();

    //windows 1
    glBegin(GL_POLYGON);                    //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.45f, 0.42f);
    glVertex2f(0.53f, 0.42f);
    glVertex2f(0.53f, 0.33f);
    glVertex2f(0.45, 0.33f);
    glEnd();

    //windows 2
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.45f, 0.22f);
    glVertex2f(0.53f, 0.22f);
    glVertex2f(0.53f, 0.13f);
    glVertex2f(0.45f, 0.13f);
    glEnd();

    //windows 3
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.45f, 0.02f);
    glVertex2f(0.53f, 0.02f);
    glVertex2f(0.53f, -0.08f);
    glVertex2f(0.45f, -0.08f);
    glEnd();
    //windows 4
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.45f, -0.18f);
    glVertex2f(0.53f, -0.18f);
    glVertex2f(0.53f, -0.27f);
    glVertex2f(0.45f, -0.27f);
    glEnd();

    //windows 4
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.45f, -0.38f);
    glVertex2f(0.53f, -0.38f);
    glVertex2f(0.53f, -0.47f);
    glVertex2f(0.45f, -0.47f);
    glEnd();
}

void building2()
{
    glBegin(GL_POLYGON);                //NAIMUL HAQUE
    glColor3ub(223, 223, 223);
    glVertex2f(0.55f, 0.88f);
    glVertex2f(0.82f, 0.88f);
    glVertex2f(0.82f, -0.59f);
    glVertex2f(0.55f, -0.59f);
    glEnd();

    //windows 1
    glBegin(GL_POLYGON);                //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.58f, 0.68f);
    glVertex2f(0.66f, 0.68f);
    glVertex2f(0.66f, 0.55f);
    glVertex2f(0.58f, 0.55f);
    glEnd();

    //windows 2
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.70f, 0.68f);
    glVertex2f(0.78f, 0.68f);
    glVertex2f(0.78f, 0.55f);
    glVertex2f(0.70f, 0.55f);
    glEnd();

    //windows 3
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.58f, 0.48f);
    glVertex2f(0.66f, 0.48f);
    glVertex2f(0.66f, 0.35f);
    glVertex2f(0.58f, 0.35f);
    glEnd();
    //windows 4
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.70f, 0.48f);
    glVertex2f(0.78f, 0.48f);
    glVertex2f(0.78f, 0.35f);
    glVertex2f(0.70f, 0.35f);
    glEnd();

    //windows 5

    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.58f, 0.28f);
    glVertex2f(0.66f, 0.28f);
    glVertex2f(0.66f, 0.15f);
    glVertex2f(0.58f, 0.15f);
    glEnd();

    //windows 6
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.70f, 0.28f);
    glVertex2f(0.78f, 0.28f);
    glVertex2f(0.78f, 0.15f);
    glVertex2f(0.70f, 0.15f);
    glEnd();

    //windows 7
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.58f, 0.08f);
    glVertex2f(0.66f, 0.08f);
    glVertex2f(0.66f, -0.05f);
    glVertex2f(0.58f, -0.05f);
    glEnd();
    //windows 8
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.70f, 0.08f);
    glVertex2f(0.78f, 0.08f);
    glVertex2f(0.78f, -0.05f);
    glVertex2f(0.70f, -0.05f);
    glEnd();

    //windows 7
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.58f, -0.12f);
    glVertex2f(0.66f, -0.12f);
    glVertex2f(0.66f, -0.25f);
    glVertex2f(0.58f, -0.25f);
    glEnd();
    //windows 8
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.70f, -0.12f);
    glVertex2f(0.78f, -0.12f);
    glVertex2f(0.78f, -0.25f);
    glVertex2f(0.70f, -0.25f);
    glEnd();
    //windows 9
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.58f, -0.32f);
    glVertex2f(0.66f, -0.32f);
    glVertex2f(0.66f, -0.45f);
    glVertex2f(0.58f, -0.45f);
    glEnd();
    //windows 10
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.70f, -0.32f);
    glVertex2f(0.78f, -0.32f);
    glVertex2f(0.78f, -0.45f);
    glVertex2f(0.70f, -0.45f);
    glEnd();
}

void building1()
{
    glBegin(GL_POLYGON);
    glColor3ub(193, 193, 193);           //NAIMUL HAQUE
    glVertex2f(0.82f, 0.69f);
    glVertex2f(0.92f, 0.69f);
    glVertex2f(0.92f, -0.59f);
    glVertex2f(0.82f, -0.59f);
    glEnd();
    //windows 1
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.84f, 0.59f);
    glVertex2f(0.90f, 0.59f);
    glVertex2f(0.90f, 0.47f);
    glVertex2f(0.84f, 0.47f);
    glEnd();

    //windows 2
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.84f, 0.39f);
    glVertex2f(0.90f, 0.39f);
    glVertex2f(0.90f, 0.27f);
    glVertex2f(0.84f, 0.27f);
    glEnd();
    //windows 2
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.84f, 0.19f);
    glVertex2f(0.90f, 0.19f);
    glVertex2f(0.90f, 0.07f);
    glVertex2f(0.84f, 0.07f);
    glEnd();

    //windows 3
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.84f, -0.01f);
    glVertex2f(0.90f, 0.01f);
    glVertex2f(0.90f, -0.13f);
    glVertex2f(0.84f, -0.13f);
    glEnd();
    //windows 4
    glBegin(GL_POLYGON);                  //NAIMUL HAQUE
    glColor3ub(255, 255, 153);
    if(!light){glColor3ub(140, 198, 255);}
    glVertex2f(0.84f, -0.21f);
    glVertex2f(0.90f, -0.21f);
    glVertex2f(0.90f, -0.33f);
    glVertex2f(0.84f, -0.33f);
    glEnd();
}

void stationRB()
{
    glPushMatrix();                        //Tanbir Yousuf
    glTranslatef(-0.35f, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor4ub(79,143,183, 200); //backglass
    glVertex2f(-0.3f, 0.05f);
    glVertex2f(0.8f, 0.05f);
    glVertex2f(0.8f, 0.4f);
    glVertex2f(-0.3f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);                    //Tanbir Yousuf
    glColor3ub(200, 200, 200);
    glVertex2f(-0.3f, 0.05f);
    glVertex2f(0.8f, 0.05f);
    glVertex2f(0.8f, 0.1f);
    glVertex2f(-0.3f, 0.1f);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(200, 200, 200);
    glVertex2f(0.8f, 0.15f);
    glVertex2f(-0.3f, 0.15f);
    glEnd();

    glBegin(GL_POLYGON);//shade                //Tanbir Yousuf
    glColor4ub(180, 180, 180,100);
    glVertex2f(-0.2f, 0.35f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(0.8f, 0.4f);
    glVertex2f(-0.3f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);                    //Tanbir Yousuf
    glColor3ub(135,1,1);
    glVertex2f(-0.3f, 0.55f);
    glVertex2f(0.8f, 0.55f);
    glVertex2f(0.9f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();
    glPopMatrix();
}

void road()
{
    glBegin(GL_POLYGON); //road             //HASAN, MD. RAKIBUL
    glColor3ub(86, 44, 44);

    glVertex2f(1.0f, -0.7f);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///bit           //HASAN, MD. RAKIBUL
    glColor3ub(195, 195, 195);

    glVertex2f(1.0f, -0.52f);
    glVertex2f(-1.0f, -0.52f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glEnd();

    glLineWidth(2.5); //road track          //HASAN, MD. RAKIBUL

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glEnd();
}




void fan()
{
    glPushMatrix();

    glTranslatef(-0.85,-0.75,0.0);
    glLineWidth(20);
    glBegin (GL_LINES);
      glColor3ub(255,255,255);                                 // white fan design of park
      glVertex2f( 0.00f, 0.00f);
      glVertex2f( 0.0f,-0.25f);
    glEnd();

    GLfloat p1 = 0.0f; GLfloat q1= 0.0f; GLfloat r1 = 0.015f;  ////fan black part
    int tringle2=40;
    float tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,0,0);
    glVertex2f (p1,q1);
    for(int i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    glPushMatrix();
        glRotated(fanrotate, 0, 0, 1);
            glBegin(GL_QUADS); // up side fan hand
                glColor3ub(255,255,255);
                glVertex2f( 0.000f, 0.015f);
                glVertex2f(-0.020f,  0.040f);
                glVertex2f( 0.000f, 0.150f);
                glVertex2f( 0.020f,  0.040f);
            glEnd();
            glBegin(GL_QUADS); // down side fan hand
                glColor3ub(255,255,255);
                glVertex2f( 0.000f,-0.015f);
                glVertex2f(-0.020f,-0.040f);
                glVertex2f( 0.000f,-0.150f);
                glVertex2f( 0.020f,-0.040f);
            glEnd();
            glBegin(GL_QUADS); // right side fan hand
                glColor3ub(255,255,255);
                glVertex2f(0.015f, 0.000f);
                glVertex2f(0.040f,-0.020f);
                glVertex2f(0.150f, 0.000f);
                glVertex2f(0.040f, 0.020f);
            glEnd();
            glBegin(GL_QUADS); // left side fan hand
                glColor3ub(255,255,255);
                glVertex2f(-0.015f, 0.000f);
                glVertex2f(-0.040f,-0.020f);
                glVertex2f(-0.150f, 0.000f);
                glVertex2f(-0.040f, 0.020f);
            glEnd();
    glPopMatrix();
    glPopMatrix();
}

void human5()
{
    glPushMatrix();
    glTranslatef(EscHumanPositionX, EscHumanPositionY, 0.0f);
                                                // human head, START
    GLfloat p1=0.490f; GLfloat q1= -0.41f; GLfloat r1 = 0.012f;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0,0,0);
    glVertex2f (p1,q1);
    for(int i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();                                  // human head, END


    p1=0.49f; q1= -0.435f; r1 = 0.012f;        // human torso, START
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (124,252,0);
    glVertex2f (p1,q1);
    for(int i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    glBegin(GL_QUADS);
	glColor3ub(124,252,0);

	glVertex2f(0.502f, -0.435f);
	glVertex2f(0.478f, -0.435f);
	glVertex2f(0.478f, -0.470f);
	glVertex2f(0.502f, -0.470f);

	glEnd();                                // human torso, END


    glLineWidth(4.5);                       // human legs, START
	glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.486f,-0.5f);
    glVertex2f(0.486f,-0.470f);
    glEnd();

    glLineWidth(4.5);
	glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.494f,-0.5f);
    glVertex2f(0.494f,-0.470f);
    glEnd();                                 // human legs, END

    glPopMatrix();

}

void human3()
{
    glPushMatrix();
    glTranslatef(RoadHumanRightmostPosition, 0.0f, 0.0f);
                                                // human head, START
    GLfloat p1=0.9f; GLfloat q1= -0.41f; GLfloat r1 = 0.012f;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0,0,0);
    glVertex2f (p1,q1);
    for(int i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();                                 // human head, END


    p1=0.9f; q1= -0.435f; r1 = 0.012f;        // human torso, START
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (34, 139, 34);
    glVertex2f (p1,q1);
    for(int i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    glBegin(GL_QUADS);
	glColor3ub(34, 139, 34);

	glVertex2f(0.912f, -0.435f);
	glVertex2f(0.888f, -0.435f);
	glVertex2f(0.888f, -0.470f);
	glVertex2f(0.912f, -0.470f);

	glEnd();                                // human torso, END


    glLineWidth(4.5);                       // human legs, START
	glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.896f,-0.5f);
    glVertex2f(0.896f,-0.470f);
    glEnd();

    glLineWidth(4.5);
	glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.904f,-0.5f);
    glVertex2f(0.904f,-0.470f);
    glEnd();                                 // human legs, END
}

void human4()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2 = 40;

    p1=0.925f; q1= -0.41f; r1 = 0.012f;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0,0,0);
    glVertex2f (p1,q1);
    for(int i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();                                 // human head, END


    p1=0.925f; q1= -0.435f; r1 = 0.012f;        // human torso, START
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255, 20, 147);
    glVertex2f (p1,q1);
    for(int i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    glBegin(GL_QUADS);
	glColor3ub(255, 20, 147);

	glVertex2f(0.937f, -0.435f);
	glVertex2f(0.913f, -0.435f);
	glVertex2f(0.913f, -0.470f);
	glVertex2f(0.937f, -0.470f);

	glEnd();                                // human torso, END


    glLineWidth(4.5);                       // human legs, START
	glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.921f,-0.5f);
    glVertex2f(0.921f,-0.470f);
    glEnd();

    glLineWidth(4.5);
	glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.929f,-0.5f);
    glVertex2f(0.929f,-0.470f);
    glEnd();                                 // human legs, END

    glPopMatrix();
}

void escalator()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2    ;
    int i;                                  // human head, START
    p1=0.925f; q1= -0.41f; r1 = 0.012f;
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);               //Esc. lower square
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, -0.425f);
    glVertex2f(0.475f, -0.425f);
    glVertex2f(0.475f, -0.5f);
    glEnd();

    p1 = 0.5; q1 = -0.4640f; r1 = 0.037f;  // Esc. lower circle
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(135, 206, 250);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
                    p1 + (r1 * cos(i * tp2 / tringle2)),
                    q1 + (r1 * sin(i * tp2 / tringle2))
                    );
    }
    glEnd();

    glBegin(GL_POLYGON);                     // Esc. angled stairway
	glColor3ub(135, 206, 250);
    glVertex2f(0.475, -0.425f);
    glVertex2f(0.2f, 0.125f);
    glVertex2f(0.2f, 0.05f);
    glVertex2f(0.475f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON);                     // Esc. angled stairway shadow
	glColor3ub(65, 105, 225);
    glVertex2f(0.475f, -0.5f);
    glVertex2f(0.2f, 0.05f);
    glVertex2f(0.2f, 0.05f);
    glVertex2f(0.46f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);                 //Esc. upper square
    glVertex2f(0.2f, 0.125f);
    glVertex2f(0.175f, 0.125f);
    glVertex2f(0.175f, 0.05f);
    glVertex2f(0.2f, 0.05f);
    glEnd();


    p1 = 0.175; q1 = 0.087f; r1 = 0.037f;   // Esc. upper circle
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(135, 206, 250);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
                    p1 + (r1 * cos(i * tp2 / tringle2)),
                    q1 + (r1 * sin(i * tp2 / tringle2))
                    );
    }
    glEnd();
}

void human1()
{
    glPushMatrix();
    glTranslatef(RoadHumanNearEscPosition, 0.0f, 0.0f);
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;                                  // human head, START
    p1=0.6f; q1= -0.41f; r1 = 0.012f;     // human head, START
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0,0,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();                                 // human head, END


    p1=0.6f; q1= -0.435f; r1 = 0.012f;        // human torso, START
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,0,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    glBegin(GL_QUADS);
	glColor3ub(255,0,0);

	glVertex2f(0.612f, -0.435f);
	glVertex2f(0.588f, -0.435f);
	glVertex2f(0.588f, -0.470f);
	glVertex2f(0.612f, -0.470f);

	glEnd();                                // human torso, END


    glLineWidth(4.5);                       // human legs, START
	glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.596f,-0.5f);
    glVertex2f(0.596f,-0.470f);
    glEnd();

    glLineWidth(4.5);
	glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.604f,-0.5f);
    glVertex2f(0.604f,-0.470f);
    glEnd();                                 // human legs, END
}

void human2()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;

    p1=0.625f; q1= -0.41f; r1 = 0.012f;
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);          // human head, START
    glColor3ub ( 0,0,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();                                 // human head, END


    p1=0.625f; q1= -0.435f; r1 = 0.012f;        // human torso, START
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,140,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    glBegin(GL_QUADS);
	glColor3ub(255,140,0);

	glVertex2f(0.637f, -0.435f);
	glVertex2f(0.613f, -0.435f);
	glVertex2f(0.613f, -0.470f);
	glVertex2f(0.637f, -0.470f);

	glEnd();                                // human torso, END


    glLineWidth(4.5);                       // human legs, START
	glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.621f,-0.5f);
    glVertex2f(0.621f,-0.470f);
    glEnd();

    glLineWidth(4.5);
	glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.629f,-0.5f);
    glVertex2f(0.629f,-0.470f);
    glEnd();                                 // human legs, END

    glPopMatrix();
}

void bus()
{
    glPushMatrix();
    glTranslatef(busposition, 0.0f, 0.0f);

    glBegin(GL_POLYGON); ///bus
    glColor3ub(255, 255, 0);
    glVertex2f(0.366667f, -0.567037f);
    glVertex2f(0.613583f, -0.567037f);
    glVertex2f(0.616667f, -0.565185f);
    glVertex2f(0.616667f, -0.415185f);
    glVertex2f(0.613583f, -0.40963f);
    glVertex2f(0.3875f, -0.40963f);
    glVertex2f(0.375f, -0.415185f);
    glVertex2f(0.366667f, -0.426296f);
    glVertex2f(0.366667f, -0.426296f);
    glVertex2f(0.3625f, -0.561481f);
    glEnd();


    glBegin(GL_POLYGON); ///bus windshield
    glColor3ub(75, 75, 75);
    glVertex2f(0.3625f, -0.448518f);
    glVertex2f(0.365583f, -0.448518f);
    glVertex2f(0.365583f, -0.531852f);
    glVertex2f(0.3625f, -0.531852f);
    glEnd();

    if(light)
    {
    glBegin(GL_POLYGON); ///bus light
    glColor4ub(255, 255, 255, 100);
    glVertex2f(0.365583f, -0.55f);
    glVertex2f(0.365583f, -0.531852f);
    glVertex2f(-0.1f, -0.55f);
    glVertex2f(0.2f, -0.6f);
    glEnd();
    }

    glBegin(GL_POLYGON); ///bus door
    glColor3ub(255, 0, 0);
    glVertex2f(0.366667f, -0.452222f);
    glVertex2f(0.390625f, -0.452222f);
    glVertex2f(0.390625f, -0.565185f);
    glVertex2f(0.366667f, -0.565185f);

    glEnd();

    glBegin(GL_POLYGON); ///bus door window
    glColor3ub(75, 75, 75);

    glVertex2f(0.36875f, -0.457778f);
    glVertex2f(0.388542f, -0.457778f);
    glVertex2f(0.388542f, -0.504074f);
    glVertex2f(0.36875f, -0.53f);
    glEnd();

    glLineWidth(2.5); ///bus door handle
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.38125f, -0.548148f);
    glVertex2f(0.3875f, -0.548148f);
    glEnd();

    glBegin(GL_POLYGON); ///bus window
    glColor3ub(75, 75, 75);

    glVertex2f(0.392708f, -0.420741f);
    glVertex2f(0.6125f, -0.420741f);
    glVertex2f(0.6125f, -0.455926f);
    glVertex2f(0.598958f, -0.48f);
    glVertex2f(0.392708f, -0.48f);
    glEnd();

    glLineWidth(2.5); ///bus window separator
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);

    glVertex2f(0.436458f, -0.420741f);
    glVertex2f(0.436458f, -0.48f);
    glEnd();

    glLineWidth(2.5); ///bus window separator
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);

    glVertex2f(0.48125f, -0.420741f);
    glVertex2f(0.48125f, -0.48f);
    glEnd();

    glLineWidth(2.5); ///bus window separator
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);

    glVertex2f(0.525f, -0.420741f);
    glVertex2f(0.525f, -0.48f);
    glEnd();

    glLineWidth(2.5); ///bus window separator
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);

    glVertex2f(0.56875f, -0.420741f);
    glVertex2f(0.56875f, -0.48f);
    glEnd();


    glLineWidth(0.5); ///bus paint stripe

    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);

    glVertex2f(0.391667f, -0.493504f);
    glVertex2f(0.396875f, -0.502763f);
    glEnd();

    glLineWidth(0.5); ///bus paint stripe

    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);

    glVertex2f(0.391667f, -0.498704f);
    glVertex2f(0.396875f, -0.507963f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);

    glVertex2f(0.396875f, -0.502763f);
    glVertex2f(0.615625f, -0.502763f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);

    glVertex2f(0.396875f, -0.507963f);
    glVertex2f(0.615625f, -0.507963f);
    glEnd();

    glBegin(GL_POLYGON); ///bus carrier
    glColor3ub(62, 30, 121);

    glVertex2f(0.438542f, -0.515926f);
    glVertex2f(0.482292f, -0.515926f);
    glVertex2f(0.482292f, -0.565185f);
    glVertex2f(0.438542f, -0.565185f);
    glEnd();


    glLineWidth(2.5);
    glBegin(GL_LINES);/// bus carrier handle

    glColor3ub(255, 255, 255);

    glVertex2f(0.458333f, -0.557778f);
    glVertex2f(0.4625f, -0.557778f);
    glEnd();

    glBegin(GL_POLYGON); ///bus carrier door
    glColor3ub(62, 30, 121);

    glVertex2f(0.501042f, -0.483704f);
    glVertex2f(0.521875f, -0.483704f);
    glVertex2f(0.521875f, -0.565185f);
    glVertex2f(0.501042f, -0.565185f);

    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);/// bus carrier door handle

    glColor3ub(255, 255, 255);

    glVertex2f(0.513542f, -0.526296f);
    glVertex2f(0.517708f, -0.526296f);
    glEnd();


    glBegin(GL_POLYGON); ///bus air ventilation
    glColor3ub(0, 255, 0);
    glVertex2f(0.5875f, -0.513333f);
    glVertex2f(0.608333f, -0.513333f);
    glVertex2f(0.608333f, -0.541111f);
    glVertex2f(0.5875f, -0.541111f);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);/// bus air ventilation rows
    glColor3ub(0, 0, 0);
    glVertex2f(0.5875f, -0.517037f);
    glVertex2f(0.608333f, -0.517037f);
    glEnd();

    glBegin(GL_LINES);/// bus air ventilation rows
    glColor3ub(0, 0, 0);
    glVertex2f(0.5875f, -0.523037f);
    glVertex2f(0.608333f, -0.523037f);
    glEnd();

    glBegin(GL_LINES);/// bus air ventilation rows
    glColor3ub(0, 0, 0);
    glVertex2f(0.5875f, -0.528037f);
    glVertex2f(0.608333f, -0.528037f);
    glEnd();

    glBegin(GL_LINES);/// bus air ventilation rows
    glColor3ub(0, 0, 0);

    glVertex2f(0.5875f, -0.533037f);
    glVertex2f(0.608333f, -0.533037f);
    glEnd();

    glBegin(GL_LINES);/// bus air ventilation rows
    glColor3ub(0, 0, 0);

    glVertex2f(0.5875f, -0.539037f);
    glVertex2f(0.608333f, -0.539037f);
    glEnd();

    glLineWidth(4.5);
    glBegin(GL_LINES);/// bus rooftop
    glColor3ub(0, 0, 0);

    glVertex2f(0.426042f, -0.40963f);
    glVertex2f(0.476042f, -0.40963f);
    glEnd();

    glBegin(GL_LINES);/// bus rooftop
    glColor3ub(0, 0, 0);

    glVertex2f(0.540625f, -0.40963f);
    glVertex2f(0.592708f, -0.40963f);
    glEnd();

    glLineWidth(4.5);
    glBegin(GL_LINES);/// bus view mirror holder
    glColor3ub(0, 0, 0);

    glVertex2f(0.363542f, -0.433704f);
    glVertex2f(0.355208f, -0.433704f);
    glEnd();
    glBegin(GL_LINES);/// bus view mirror holder
    glColor3ub(0, 0, 0);

    glVertex2f(0.355208f, -0.433704f);
    glVertex2f(0.355208f, -0.452963f);
    glEnd();

    glLineWidth(7.0);
    glBegin(GL_LINES);/// bus view mirror
    glColor3ub(255, 0, 0);

    glVertex2f(0.355208f, -0.452963f);
    glVertex2f(0.355208f, -0.48f);
    glEnd();
    ///bus wheel
    int b;

    GLfloat buswheelXLp = 0.4125f; GLfloat buswheelXLq = -0.563333f;
    GLfloat  buswheelXLr = 0.015542f;
    int buswheelXLtri = 40;

    GLfloat  buswheelXLtp = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);

    glVertex2f(buswheelXLp, buswheelXLq);
    for (b = 0;b <= buswheelXLtri; b++)
    {
        glVertex2f(buswheelXLp + (buswheelXLr * cos(b * buswheelXLtp / buswheelXLtri)),
            buswheelXLq + (buswheelXLr * sin(b * buswheelXLtp / buswheelXLtri)));
    }
    glEnd();

    buswheelXLp = 0.4125f;  buswheelXLq = -0.563333f;   buswheelXLr = 0.007992f;
    buswheelXLtri = 40;

    buswheelXLtp = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);

    glVertex2f(buswheelXLp, buswheelXLq);
    for (b = 0;b <= buswheelXLtri; b++)
    {
        glVertex2f(buswheelXLp + (buswheelXLr * cos(b * buswheelXLtp / buswheelXLtri)),
            buswheelXLq + (buswheelXLr * sin(b * buswheelXLtp / buswheelXLtri)));
    }
    glEnd();

    buswheelXLp = 0.5625f;  buswheelXLq = -0.563333f;
    buswheelXLr = 0.015542f;
    buswheelXLtri = 40;

    buswheelXLtp = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);

    glVertex2f(buswheelXLp, buswheelXLq);
    for (b = 0;b <= buswheelXLtri; b++)
    {
        glVertex2f(buswheelXLp + (buswheelXLr * cos(b * buswheelXLtp / buswheelXLtri)),
            buswheelXLq + (buswheelXLr * sin(b * buswheelXLtp / buswheelXLtri)));
    }
    glEnd();

    buswheelXLp = 0.5625f;  buswheelXLq = -0.563333f;   buswheelXLr = 0.007992f;
    buswheelXLtri = 40;

    buswheelXLtp = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);

    glVertex2f(buswheelXLp, buswheelXLq);
    for (b = 0;b <= buswheelXLtri; b++)
    {
        glVertex2f(buswheelXLp + (buswheelXLr * cos(b * buswheelXLtp / buswheelXLtri)),
            buswheelXLq + (buswheelXLr * sin(b * buswheelXLtp / buswheelXLtri)));
    }
    glEnd();
    glPopMatrix();
}

void car()
{
    glPushMatrix();
    glTranslatef(carposition, 0.0f, 0.0f);
    glBegin(GL_POLYGON); ///car body
    glColor3ub(52, 109, 203);

    glVertex2f(-0.0479167f, -0.642963f);
    glVertex2f(0.180208f, -0.642963f);
    glVertex2f(0.190625f, -0.628148f);
    glVertex2f(0.190625f, -0.611481f);
    glVertex2f(0.185417f, -0.60963f);
    glVertex2f(0.18125f, -0.55037f);
    glVertex2f(0.107292f, -0.537407f);
    glVertex2f(0.0729167f, -0.483704f);
    glVertex2f(0.0666667f, -0.478148f);
    glVertex2f(0.0270833f, -0.472593f);
    glVertex2f(-0.0229167f, -0.48f);
    glVertex2f(-0.059375f, -0.528148f);
    glVertex2f(-0.0854167f, -0.535556f);
    glVertex2f(-0.0895833f, -0.544815f);
    glVertex2f(-0.0854167f, -0.622593f);
    glVertex2f(-0.075f, -0.637407f);

    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);/// car body stripes

    glColor3ub(45, 45, 45);

    glVertex2f(-0.0875f, -0.541111f);
    glVertex2f(0.104167f, -0.55037f);

    glEnd();
    glBegin(GL_LINES);/// car body stripes

    glColor3ub(45, 45, 45);

    glVertex2f(0.104167f, -0.55037f);
    glVertex2f(0.180208f, -0.568889f);

    glEnd();
    glLineWidth(1.5);
    glBegin(GL_LINES);/// car body stripes

    glColor3ub(0, 0, 0);

    glVertex2f(0.103125f, -0.542963f);
    glVertex2f(0.179167f, -0.561481f);

    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);/// car body stripes

    glColor3ub(45, 45, 45);

    glVertex2f(-0.0885417f, -0.557778f);
    glVertex2f(0.171875f, -0.568889f);

    glEnd();


    glBegin(GL_POLYGON); ///car window z
    glColor3ub(0, 0, 0);

    glVertex2f(-0.00625f, -0.487407f);
    glVertex2f(0.0583333f, -0.487407f);
    glVertex2f(0.0666667f, -0.496667f);
    glVertex2f(0.0875f, -0.541111f);
    glVertex2f(-0.021875f, -0.535556f);
    glVertex2f(-0.009375f, -0.492963f);

    glEnd();

    glBegin(GL_POLYGON); ///car window x
    glColor3ub(0, 0, 0);

    glVertex2f(0.0730167f, -0.483704f);
    glVertex2f(0.071875f, -0.492963f);
    glVertex2f(0.0958333f, -0.541111f);
    glVertex2f(0.10725f, -0.537407f);

    glEnd();

    glBegin(GL_POLYGON); ///car window -x
    glColor3ub(0, 0, 0);

    glVertex2f(-0.021875f, -0.481852f);
    glVertex2f(-0.0218333f, -0.492963f);
    glVertex2f(-0.041625f, -0.526296f);
    glVertex2f(-0.05625f, -0.522593f);

    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);/// car back door upper

    glColor3ub(0, 0, 0);

    glVertex2f(-0.019875f, -0.529259f);
    glVertex2f(-0.019875f, -0.554074f);
    glEnd();
    glBegin(GL_LINES);/// car back door lower

    glColor3ub(0, 0, 0);

    glVertex2f(-0.019875f, -0.554074f);
    glVertex2f(-0.0125f, -0.563333f);
    glEnd();

    glBegin(GL_LINES);/// car back door lower

    glColor3ub(0, 0, 0);

    glVertex2f(-0.0125f, -0.563333f);
    glVertex2f(-0.00104167f, -0.611481f);
    glEnd();

    glBegin(GL_LINES);/// car back door lower

    glColor3ub(0, 0, 0);

    glVertex2f(-0.00104167f, -0.611481f);
    glVertex2f(0.0f, -0.62f);
    glEnd();
    glBegin(GL_LINES);/// car back door lower

    glColor3ub(0, 0, 0);

    glVertex2f(0.0f, -0.62f);
    glVertex2f(0.090625f, -0.62f);
    glEnd();

    glBegin(GL_LINES);/// car back door lower

    glColor3ub(0, 0, 0);

    glVertex2f(0.090625f, -0.62f);
    glVertex2f(0.0989583f, -0.598519f);
    glEnd();

    glBegin(GL_LINES);/// car front door

    glColor3ub(0, 0, 0);

    glVertex2f(0.0989583f, -0.598519f);
    glVertex2f(0.0989583f, -0.578148f);


    glEnd();

    glBegin(GL_LINES);/// car front door

    glColor3ub(0, 0, 0);

    glVertex2f(0.0989583f, -0.578148f);
    glVertex2f(0.0875f, -0.541111f);

    glEnd();

    glBegin(GL_LINES);/// car door divider

    glColor3ub(0, 0, 0);

    glVertex2f(0.0333333f, -0.537963f);
    glVertex2f(0.0301667f, -0.572593f);

    glEnd();

    glBegin(GL_LINES);/// car door divider

    glColor3ub(0, 0, 0);

    glVertex2f(0.0301667f, -0.572593f);
    glVertex2f(0.0353333f, -0.620963f);

    glEnd();

    glLineWidth(4.5);
    glBegin(GL_LINES);/// car window divider

    glColor3ub(52, 109, 203);

    glVertex2f(0.0332083f, -0.487407f);
    glVertex2f(0.0332083f, -0.540963f);

    glEnd();
    glLineWidth(2.5);
    glBegin(GL_LINES);/// car window divider

    glColor3ub(0, 0, 0);

    glVertex2f(-0.021875f, -0.537007f);
    glVertex2f(0.0864583f, -0.543163f);

    glEnd();



    glBegin(GL_POLYGON); ///car side mirror
    glColor3ub(255, 0, 0);

    glVertex2f(0.0708333f, -0.544815f);
    glVertex2f(0.0864583f, -0.542963f);
    glVertex2f(0.0802083f, -0.528148f);
    glVertex2f(0.0708333f, -0.531852f);


    glEnd();

    glBegin(GL_POLYGON); ///car front ventilator
    glColor3ub(0, 0, 0);

    glVertex2f(0.179167f, -0.561481f);
    glVertex2f(0.186333f, -0.554074f);
    glVertex2f(0.191542f, -0.611481f);
    glVertex2f(0.185417f, -0.611481f);

    glEnd();

    glBegin(GL_POLYGON); ///car headlight hole
    glColor3ub(0, 0, 0);
    glVertex2f(0.164667f, -0.570741f);
    glVertex2f(0.177167f, -0.570741f);
    glVertex2f(0.177167f, -0.598519f);
    glVertex2f(0.167792f, -0.598519f);
    glEnd();

    glBegin(GL_POLYGON); ///car headlight
    glColor3ub(255, 255, 255);
    glVertex2f(0.173958f, -0.570741f);
    glVertex2f(0.179167f, -0.570741f);
    glVertex2f(0.179167f, -0.598519f);
    glVertex2f(0.173958f, -0.598519f);
    glEnd();

    if(light)
    {
        glBegin(GL_POLYGON); ///car light
        glColor4ub(255, 255, 255, 100);
        glVertex3f(0.173958f, -0.570741f, 0.5f);
        glVertex3f(0.5f, -0.6f, 0.5f);
        glVertex3f(0.25f, -0.63f, 0.5f);
        glVertex3f(0.173958f, -0.598519f, 0.5f);
        glEnd();
    }

    glBegin(GL_POLYGON); ///car stoplight
    glColor3ub(255, 0, 0);
    glVertex2f(-0.0906417f, -0.55963f);
    glVertex2f(-0.0823083f, -0.55963f);
    glVertex2f(-0.0771f, -0.591111f);
    glVertex2f(-0.0885583f, -0.591111f);
    glEnd();

    //	 glBegin(GL_LINES); ///car stoplight
    //	glColor3ub(148, 148, 148);
    //
    //	glVertex2f(-0.0884167f,-0.611481f);
    //	glVertex2f(0.191542f,-0.611481f);
    //
    //	glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES); ///car exhaust
    glColor3ub(0, 0, 0);
    glVertex2f(0.191542f, -0.625593f);
    glVertex2f(-0.087375f, -0.625593f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES); ///strip below car exhaust
    glColor3ub(0, 0, 0);
    glVertex2f(-0.0697917f, -0.633704f);
    glVertex2f(-0.0510417f, -0.633704f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES); ///strip below car exhaust
    glColor3ub(0, 0, 0);
    glVertex2f(0.166833f, -0.633704f);
    glVertex2f(0.182458f, -0.633704f);
    glEnd();

    ///car wheel
    int c;
    int carwheelXLtri = 40;
    GLfloat carwheelXLp = -0.0230417f;
    GLfloat carwheelXLq = -0.641148f;
    GLfloat carwheelXLr = 0.0283583f;
    GLfloat carwheelXLtp = 1.0f * PI;

    glBegin(GL_TRIANGLE_FAN);///left wheel cover
    glColor3ub(31, 83, 88);


    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    carwheelXLr = 0.02275f;


    carwheelXLtp = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);///left wheel tier
    glColor3ub(0, 0, 0);

    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    carwheelXLr = 0.01235416f;
    glBegin(GL_TRIANGLE_FAN);///left wheel
    glColor3ub(255, 255, 255);

    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    carwheelXLr = 0.00625f;
    //    glBegin(GL_TRIANGLE_FAN);///left wheel center wheel
    //    glColor3ub(0,0,0);
    //
    //    glVertex2f(carwheelXLp,carwheelXLq);
    //    for (c = 0;c <= carwheelXLtri; c++)
    //    {
    //        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
    //            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri )));
    //    }
    //    glEnd();


        ///car right wheel

    carwheelXLp = -0.0230417f + 0.1635003f;
    carwheelXLq = -0.641148f;
    carwheelXLr = 0.0283583f;
    carwheelXLtp = 1.0f * PI;

    glBegin(GL_TRIANGLE_FAN);///right wheel cover
    glColor3ub(31, 83, 88);


    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    carwheelXLr = 0.02275f;


    carwheelXLtp = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);///right wheel tier
    glColor3ub(0, 0, 0);

    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    carwheelXLr = 0.01235416f;
    glBegin(GL_TRIANGLE_FAN);///right wheel
    glColor3ub(255, 255, 255);

    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    int smokeXLtri = 40;
    GLfloat smokeXLp =-0.094875f;
    GLfloat smokeXLq = -0.627778f;
    GLfloat smokeXLr = 0.0143583f;
    GLfloat smokeXLtp = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);///car smoke
        glColor4ub(200, 200, 200, 200);



    glVertex2f(smokeXLp, smokeXLq);
    for (c = 0;c <= smokeXLtri; c++)
    {
        glVertex2f(smokeXLp + (smokeXLr * cos(c * smokeXLtp / smokeXLtri)),
            smokeXLq + (smokeXLr * sin(c * smokeXLtp / smokeXLtri)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);///car smoke2
       glColor4ub(200, 200, 200, 150);
     smokeXLp =-0.119875f;
    smokeXLq = -0.627778f;
    smokeXLr = 0.0223583f;
    smokeXLtp = 2.0f * PI;

    glVertex2f(smokeXLp, smokeXLq);
    for (c = 0;c <= smokeXLtri; c++)
    {
        glVertex2f(smokeXLp + (smokeXLr * cos(c * smokeXLtp / smokeXLtri)),
            smokeXLq + (smokeXLr * sin(c * smokeXLtp / smokeXLtri)));
    }
    glEnd();

    glPushMatrix();
    glTranslatef(carSmokeposition, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);///car smoke2
       glColor4ub(200, 200, 200, 100);
     smokeXLp =-0.139875f;
    smokeXLq = -0.627778f;
    smokeXLr = 0.0223583f;
    smokeXLtp = 2.0f * PI;


    glVertex2f(smokeXLp, smokeXLq);
    for (c = 0;c <= smokeXLtri; c++)
    {
        glVertex2f(smokeXLp + (smokeXLr * cos(c * smokeXLtp / smokeXLtri)),
            smokeXLq + (smokeXLr * sin(c * smokeXLtp / smokeXLtri)));
    }
    glEnd();
    glPopMatrix();


    carwheelXLr = 0.00625f;
    //    glBegin(GL_TRIANGLE_FAN);///right wheel center wheel
    //    glColor3ub(0,0,0);
    //
    //    glVertex2f(carwheelXLp,carwheelXLq);
    //    for (c = 0;c <= carwheelXLtri; c++)
    //    {
    //        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
    //            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri )));
    //    }
    //    glEnd();

    glPopMatrix();
}

void train()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;
    glPushMatrix();

    glTranslatef(position, 0.0f, 0.0f);
    p1 = -0.88f;  q1 = 0.149f;  r1 = 0.101f; ////Left SIDE door goal blue ta
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 255, 127);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();


    p1 = 0.495f; q1 = 0.149f; r1 = 0.101f; ////RIGHT SIDE door goal blue ta
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 255, 127);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // left side first bogir er sathe 2nd bogir picher black connection
    glVertex2f(-0.85f, 0.06f);
    glVertex2f(-0.85f, 0.24f);
    glVertex2f(-0.6f, 0.24f);
    glVertex2f(-0.6f, 0.06f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 255, 127); // left sider er 1st train bogi jekhane theke calabe
    glVertex2f(-0.87f, 0.05f);
    glVertex2f(-0.87f, 0.25f);
    glVertex2f(-0.7f, 0.25f);
    glVertex2f(-0.7f, 0.05f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); // left sider er 1st train bogi r janala
    if(!light){glColor3ub(255,239,213);}
    glVertex2f(-0.78f, 0.13f);
    glVertex2f(-0.78f, 0.22f);
    glVertex2f(-0.72f, 0.22f);
    glVertex2f(-0.72f, 0.13);
    glEnd();

    p1 = -0.765f; q1 = 0.15f; r1 = 0.015f; ////first bogir man 1
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();

    p1 = -0.735f; q1 = 0.15f; r1 = 0.015f; ////first bogir man 2
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(1, 1, 1); // left sider er 1st train bogi r dorja
    glVertex2f(-0.80f, 0.05f);
    glVertex2f(-0.80f, 0.18f);
    glVertex2f(-0.85f, 0.18f);
    glVertex2f(-0.85f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(1, 1, 1); // calok er cabin left er ta
    glVertex2f(-0.87f, 0.05f);
    glVertex2f(-0.93f, 0.11f);
    glVertex2f(-0.93f, 0.18f);
    glVertex2f(-0.87f, 0.25f);
    glEnd();





    /*glBegin(GL_TRIANGLES); // left side er triangle
    glColor3ub(0,139,139);
    glVertex2f(-0.87f, 0.05f);
    glVertex2f(-0.94f, 0.15f);
    glVertex2f(-0.87f, 0.25f);
    glEnd();
    */

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // 2nd bogir er sathe 3rd bogir picher black connection
    glVertex2f(-0.67f, 0.06f);
    glVertex2f(-0.67f, 0.24f);
    glVertex2f(-0.35f, 0.24f);
    glVertex2f(-0.35f, 0.06f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 255, 127); //  2nd bogi screen er left side er
    glVertex2f(-0.69f, 0.05f);
    glVertex2f(-0.69f, 0.25f);
    glVertex2f(-0.45f, 0.25f);
    glVertex2f(-0.45f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); // left sider er 2nd train bogi r left janala
    if(!light){glColor3ub(255,239,213);}
    glVertex2f(-0.68f, 0.13f);
    glVertex2f(-0.68f, 0.22f);
    glVertex2f(-0.62f, 0.22f);
    glVertex2f(-0.62f, 0.13);
    glEnd();

    p1 = -0.665f; q1 = 0.15f; r1 = 0.015f; ////2nd  bogir left janala 1st man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();


    p1 = -0.635f; q1 = 0.15f; r1 = 0.015f; ////2nd  bogir left janala 2nd man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); // left sider er 2nd train bogi r right janala
    if(!light){glColor3ub(255,239,213);}
    glVertex2f(-0.52f, 0.13f);
    glVertex2f(-0.52f, 0.22f);
    glVertex2f(-0.46f, 0.22f);
    glVertex2f(-0.46f, 0.13);
    glEnd();


    p1 = -0.506f; q1 = 0.15f; r1 = 0.015f; ////2nd  bogir right janala 1st man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();


    p1 = -0.476f; q1 = 0.15f; r1 = 0.015f; ////2nd  bogir righ janala 2nd man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(1, 1, 1); // left sider er 2nd train bogi r dorja
    glVertex2f(-0.54f, 0.05f);
    glVertex2f(-0.54f, 0.18f);
    glVertex2f(-0.60f, 0.18f);
    glVertex2f(-0.60f, 0.05f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // 3rd  bogir er sathe 4th bogir picher black connection
    glVertex2f(-0.42f, 0.06f);
    glVertex2f(-0.42f, 0.24f);
    glVertex2f(-0.1f, 0.24f);
    glVertex2f(-0.1f, 0.06f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 255, 127); // 3rd bogi screen er left side er
    glVertex2f(-0.44f, 0.05f);
    glVertex2f(-0.44f, 0.25f);
    glVertex2f(-0.2f, 0.25f);
    glVertex2f(-0.2f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); // left sider er 3rd train bogi r left janala
    if(!light){glColor3ub(255,239,213);}
    glVertex2f(-0.43f, 0.13f);
    glVertex2f(-0.43f, 0.22f);
    glVertex2f(-0.37f, 0.22f);
    glVertex2f(-0.37f, 0.13);
    glEnd();


    p1 = -0.416f; q1 = 0.15f; r1 = 0.015f; ////3rd  bogir left janala 1st man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();


    p1 = -0.385f; q1 = 0.15f; r1 = 0.015f; ////3rd  bogir left janala 2nd man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(1, 1, 1); // left sider er 3rd train bogi r dorja
    glVertex2f(-0.35f, 0.05f);
    glVertex2f(-0.35f, 0.18f);
    glVertex2f(-0.29f, 0.18f);
    glVertex2f(-0.29f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); // left sider er 3rd train bogi r right janala
    if(!light){glColor3ub(255,239,213);}
    glVertex2f(-0.27f, 0.13f);
    glVertex2f(-0.27f, 0.22f);
    glVertex2f(-0.21f, 0.22f);
    glVertex2f(-0.21f, 0.13);
    glEnd();

    p1 = -0.255f; q1 = 0.15f; r1 = 0.015f; ////3rd  bogir right janala 1st man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();


    p1 = -0.227f; q1 = 0.15f; r1 = 0.015f; ////3rd  bogir right janala 2nd man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // 4th bogir er sathe 5th bogir picher black connection
    glVertex2f(-0.17f, 0.06f);
    glVertex2f(-0.17f, 0.24f);
    glVertex2f(0.03f, 0.24f);
    glVertex2f(0.03f, 0.06f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 255, 127); // 4th bogi screen er left side er
    glVertex2f(-0.19f, 0.05f);
    glVertex2f(-0.19f, 0.25f);
    glVertex2f(0.05f, 0.25f);
    glVertex2f(0.05f, 0.05f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); // left sider er 4th train bogi r left janala
    if(!light){glColor3ub(255,239,213);}
    glVertex2f(-0.18f, 0.13f);
    glVertex2f(-0.18f, 0.22f);
    glVertex2f(-0.12f, 0.22f);
    glVertex2f(-0.12f, 0.13);
    glEnd();



    p1 = -0.165; q1 = 0.15f; r1 = 0.015f; ////4th  bogir left janala 1st man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();


    p1 = -0.135f; q1 = 0.15f; r1 = 0.015f; ////4th  bogir left janala 2nd man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(1, 1, 1); // left sider er 4th train bogi r dorja
    glVertex2f(-0.10f, 0.05f);
    glVertex2f(-0.10f, 0.18f);
    glVertex2f(-0.04, 0.18f);
    glVertex2f(-0.04f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); // left sider er 4th train bogi r right janala
    if(!light){glColor3ub(255,239,213);}
    glVertex2f(0.04f, 0.13f);
    glVertex2f(0.04f, 0.22f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(-0.02f, 0.13);
    glEnd();


    p1 = 0.025; q1 = 0.15f; r1 = 0.015f; ////4th  bogir right janala 1st man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();


    p1 = -0.005f; q1 = 0.15f; r1 = 0.015f; ////4th  bogir right janala 2nd man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // 5th bogir er sathe right last bogir picher black connection
    glVertex2f(0.05f, 0.06f);
    glVertex2f(0.05f, 0.24f);
    glVertex2f(0.33f, 0.24f);
    glVertex2f(0.33f, 0.06f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 255, 127); // 5th bogi screen er left side er
    glVertex2f(0.06f, 0.05f);
    glVertex2f(0.06f, 0.25f);
    glVertex2f(0.30f, 0.25f);
    glVertex2f(0.30f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); // left sider er 5th train bogi r left janala
    if(!light){glColor3ub(255,239,213);}
    glVertex2f(0.07f, 0.13f);
    glVertex2f(0.07f, 0.22f);
    glVertex2f(0.13f, 0.22f);
    glVertex2f(0.13f, 0.13);
    glEnd();

    p1 = 0.083; q1 = 0.15f; r1 = 0.015f; ////5th  bogir left janala 1st man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();

    p1 = 0.117f; q1 = 0.15f; r1 = 0.015f; ////5th  bogir left janala 2nd man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(1, 1, 1); // left sider er 5th train bogi r dorja
    glVertex2f(0.15f, 0.05f);
    glVertex2f(0.15f, 0.18f);
    glVertex2f(0.21, 0.18f);
    glVertex2f(0.21f, 0.05f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); // left sider er 5th train bogi r right janala
    if(!light){glColor3ub(255,239,213);}
    glVertex2f(0.23f, 0.13f);
    glVertex2f(0.23f, 0.22f);
    glVertex2f(0.29f, 0.22f);
    glVertex2f(0.29f, 0.13);
    glEnd();

    p1 = 0.245; q1 = 0.15f; r1 = 0.015f; ////5th  bogir right janala 1st man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();

    p1 = 0.275; q1 = 0.15f; r1 = 0.015f; ////5th  bogir right janala 2nd man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 255, 127); // right side er last bogi
    glVertex2f(0.31f, 0.05f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.49f, 0.25f);
    glVertex2f(0.49f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); // left sider er last train bogi r  janala
    if(!light){glColor3ub(255,239,213);}
    glVertex2f(0.32f, 0.13f);
    glVertex2f(0.32f, 0.22f);
    glVertex2f(0.38f, 0.22f);
    glVertex2f(0.38f, 0.13);
    glEnd();

    p1 = 0.335; q1 = 0.15f; r1 = 0.015f; ////last bogir right janala 1st man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();

    p1 = 0.365; q1 = 0.15f; r1 = 0.015f; ////last bogir right janala 2nd man
    tringle2 = 40;
    tp2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(1, 1, 1);
    glVertex2f(p1, q1);
    for (i = 0; i <= tringle2; i++)
    {
        glVertex2f(
            p1 + (r1 * cos(i * tp2 / tringle2)),
            q1 + (r1 * sin(i * tp2 / tringle2))
        );
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(1, 1, 1); // righ sider er last train bogi r dorja
    glVertex2f(0.41f, 0.05f);
    glVertex2f(0.41, 0.18f);
    glVertex2f(0.47, 0.18f);
    glVertex2f(0.47f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(1, 1, 1); // calok er cabin left er ta
    glVertex2f(0.49f, 0.05f);
    glVertex2f(0.54f, 0.11f);
    glVertex2f(0.54f, 0.18f);
    glVertex2f(0.49f, 0.25f);
    glEnd();

    glPopMatrix();
}

void stationFP()
{
    glPushMatrix();
    glTranslatef(-0.35f, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(91, 91, 91);
    glVertex2f(-0.2f, 0.05f);
    glVertex2f(-0.15f, 0.05f);
    glVertex2f(-0.15f, 0.4f);
    glVertex2f(-0.2f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(91, 91, 91);
    glVertex2f(0.0f, 0.05f);
    glVertex2f(0.05f, 0.05f);
    glVertex2f(0.05f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(91, 91, 91);
    glVertex2f(0.5f, 0.05f);
    glVertex2f(0.45f, 0.05f);
    glVertex2f(0.45f, 0.4f);
    glVertex2f(0.5f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(91, 91, 91);
    glVertex2f(0.7f, 0.05f);
    glVertex2f(0.65f, 0.05f);
    glVertex2f(0.65f, 0.4f);
    glVertex2f(0.7f, 0.4f);
    glEnd();

    glPopMatrix();
}

void car2()
{
    glPushMatrix();
    glTranslatef(carposition2, 0.0f, 0.0f);

    ///car
    glBegin(GL_POLYGON); ///car body
    glColor3ub(181, 230, 29);

    glVertex2f(-0.0479167f, -0.642963f);
    glVertex2f(0.180208f, -0.642963f);
    glVertex2f(0.190625f, -0.628148f);
    glVertex2f(0.190625f, -0.611481f);
    glVertex2f(0.185417f, -0.60963f);
    glVertex2f(0.18125f, -0.55037f);
    glVertex2f(0.107292f, -0.537407f);
    glVertex2f(0.0729167f, -0.483704f);
    glVertex2f(0.0666667f, -0.478148f);
    glVertex2f(0.0270833f, -0.472593f);
    glVertex2f(-0.0229167f, -0.48f);
    glVertex2f(-0.059375f, -0.528148f);
    glVertex2f(-0.0854167f, -0.535556f);
    glVertex2f(-0.0895833f, -0.544815f);
    glVertex2f(-0.0854167f, -0.622593f);
    glVertex2f(-0.075f, -0.637407f);

    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);/// car body stripes

    glColor3ub(45, 45, 45);

    glVertex2f(-0.0875f, -0.541111f);
    glVertex2f(0.104167f, -0.55037f);

    glEnd();
    glBegin(GL_LINES);/// car body stripes

    glColor3ub(45, 45, 45);

    glVertex2f(0.104167f, -0.55037f);
    glVertex2f(0.180208f, -0.568889f);

    glEnd();
    glLineWidth(1.5);
    glBegin(GL_LINES);/// car body stripes

    glColor3ub(0, 0, 0);

    glVertex2f(0.103125f, -0.542963f);
    glVertex2f(0.179167f, -0.561481f);

    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);/// car body stripes

    glColor3ub(45, 45, 45);

    glVertex2f(-0.0885417f, -0.557778f);
    glVertex2f(0.171875f, -0.568889f);

    glEnd();


    glBegin(GL_POLYGON); ///car window z
    glColor3ub(0, 0, 0);

    glVertex2f(-0.00625f, -0.487407f);
    glVertex2f(0.0583333f, -0.487407f);
    glVertex2f(0.0666667f, -0.496667f);
    glVertex2f(0.0875f, -0.541111f);
    glVertex2f(-0.021875f, -0.535556f);
    glVertex2f(-0.009375f, -0.492963f);

    glEnd();

    glBegin(GL_POLYGON); ///car window x
    glColor3ub(0, 0, 0);

    glVertex2f(0.0730167f, -0.483704f);
    glVertex2f(0.071875f, -0.492963f);
    glVertex2f(0.0958333f, -0.541111f);
    glVertex2f(0.10725f, -0.537407f);

    glEnd();

    glBegin(GL_POLYGON); ///car window -x
    glColor3ub(0, 0, 0);

    glVertex2f(-0.021875f, -0.481852f);
    glVertex2f(-0.0218333f, -0.492963f);
    glVertex2f(-0.041625f, -0.526296f);
    glVertex2f(-0.05625f, -0.522593f);

    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);/// car back door upper

    glColor3ub(0, 0, 0);

    glVertex2f(-0.019875f, -0.529259f);
    glVertex2f(-0.019875f, -0.554074f);
    glEnd();
    glBegin(GL_LINES);/// car back door lower

    glColor3ub(0, 0, 0);

    glVertex2f(-0.019875f, -0.554074f);
    glVertex2f(-0.0125f, -0.563333f);
    glEnd();

    glBegin(GL_LINES);/// car back door lower

    glColor3ub(0, 0, 0);

    glVertex2f(-0.0125f, -0.563333f);
    glVertex2f(-0.00104167f, -0.611481f);
    glEnd();

    glBegin(GL_LINES);/// car back door lower

    glColor3ub(0, 0, 0);

    glVertex2f(-0.00104167f, -0.611481f);
    glVertex2f(0.0f, -0.62f);
    glEnd();
    glBegin(GL_LINES);/// car back door lower

    glColor3ub(0, 0, 0);

    glVertex2f(0.0f, -0.62f);
    glVertex2f(0.090625f, -0.62f);
    glEnd();

    glBegin(GL_LINES);/// car back door lower

    glColor3ub(0, 0, 0);

    glVertex2f(0.090625f, -0.62f);
    glVertex2f(0.0989583f, -0.598519f);
    glEnd();

    glBegin(GL_LINES);/// car front door

    glColor3ub(0, 0, 0);

    glVertex2f(0.0989583f, -0.598519f);
    glVertex2f(0.0989583f, -0.578148f);


    glEnd();

    glBegin(GL_LINES);/// car front door

    glColor3ub(0, 0, 0);

    glVertex2f(0.0989583f, -0.578148f);
    glVertex2f(0.0875f, -0.541111f);

    glEnd();

    glBegin(GL_LINES);/// car door divider

    glColor3ub(0, 0, 0);

    glVertex2f(0.0333333f, -0.537963f);
    glVertex2f(0.0301667f, -0.572593f);

    glEnd();

    glBegin(GL_LINES);/// car door divider

    glColor3ub(0, 0, 0);

    glVertex2f(0.0301667f, -0.572593f);
    glVertex2f(0.0353333f, -0.620963f);

    glEnd();

    glLineWidth(4.5);
    glBegin(GL_LINES);/// car window divider

    glColor3ub(181, 230, 29);

    glVertex2f(0.0332083f, -0.487407f);
    glVertex2f(0.0332083f, -0.540963f);

    glEnd();
    glLineWidth(2.5);
    glBegin(GL_LINES);/// car window divider

    glColor3ub(0, 0, 0);

    glVertex2f(-0.021875f, -0.537007f);
    glVertex2f(0.0864583f, -0.543163f);

    glEnd();



    glBegin(GL_POLYGON); ///car side mirror
    glColor3ub(255, 0, 0);

    glVertex2f(0.0708333f, -0.544815f);
    glVertex2f(0.0864583f, -0.542963f);
    glVertex2f(0.0802083f, -0.528148f);
    glVertex2f(0.0708333f, -0.531852f);


    glEnd();

    glBegin(GL_POLYGON); ///car front ventilator
    glColor3ub(0, 0, 0);

    glVertex2f(0.179167f, -0.561481f);
    glVertex2f(0.186333f, -0.554074f);
    glVertex2f(0.191542f, -0.611481f);
    glVertex2f(0.185417f, -0.611481f);

    glEnd();

    glBegin(GL_POLYGON); ///car headlight hole
    glColor3ub(0, 0, 0);
    glVertex2f(0.164667f, -0.570741f);
    glVertex2f(0.177167f, -0.570741f);
    glVertex2f(0.177167f, -0.598519f);
    glVertex2f(0.167792f, -0.598519f);
    glEnd();

    glBegin(GL_POLYGON); ///car headlight
    glColor3ub(255, 255, 255);
    glVertex2f(0.173958f, -0.570741f);
    glVertex2f(0.179167f, -0.570741f);
    glVertex2f(0.179167f, -0.598519f);
    glVertex2f(0.173958f, -0.598519f);
    glEnd();

    if(light)
    {
        glBegin(GL_POLYGON); ///car light
        glColor4ub(255, 255, 255, 100);
        glVertex3f(0.173958f, -0.570741f, 0.5f);
        glVertex3f(0.5f, -0.6f, 0.5f);
        glVertex3f(0.25f, -0.63f, 0.5f);
        glVertex3f(0.173958f, -0.598519f, 0.5f);
        glEnd();
    }


    glBegin(GL_POLYGON); ///car stoplight
    glColor3ub(255, 0, 0);
    glVertex2f(-0.0906417f, -0.55963f);
    glVertex2f(-0.0823083f, -0.55963f);
    glVertex2f(-0.0771f, -0.591111f);
    glVertex2f(-0.0885583f, -0.591111f);
    glEnd();


    glLineWidth(2.5);
    glBegin(GL_LINES); ///car exhaust
    glColor3ub(0, 0, 0);
    glVertex2f(0.191542f, -0.625593f);
    glVertex2f(-0.087375f, -0.625593f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES); ///strip below car exhaust
    glColor3ub(0, 0, 0);
    glVertex2f(-0.0697917f, -0.633704f);
    glVertex2f(-0.0510417f, -0.633704f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES); ///strip below car exhaust
    glColor3ub(0, 0, 0);
    glVertex2f(0.166833f, -0.633704f);
    glVertex2f(0.182458f, -0.633704f);
    glEnd();

    ///car wheel
     int c;
     GLfloat carwheelXLtri = 40;
     GLfloat carwheelXLp = -0.0230417f;
     GLfloat carwheelXLq = -0.641148f;
     GLfloat carwheelXLr = 0.0283583f;
     GLfloat carwheelXLtp = 1.0f * PI;

    glBegin(GL_TRIANGLE_FAN);///left wheel cover
    glColor3ub(31, 83, 88);


    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    carwheelXLr = 0.02275f;


    carwheelXLtp = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);///left wheel tier
    glColor3ub(0, 0, 0);

    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    carwheelXLr = 0.01235416f;
    glBegin(GL_TRIANGLE_FAN);///left wheel
    glColor3ub(255, 255, 255);

    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    carwheelXLr = 0.00625f;
    //    glBegin(GL_TRIANGLE_FAN);///left wheel center wheel
    //    glColor3ub(0,0,0);
    //
    //    glVertex2f(carwheelXLp,carwheelXLq);
    //    for (c = 0;c <= carwheelXLtri; c++)
    //    {
    //        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
    //            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri )));
    //    }
    //    glEnd();


        ///car right wheel

    carwheelXLp = -0.0230417f + 0.1635003f;
    carwheelXLq = -0.641148f;
    carwheelXLr = 0.0283583f;
    carwheelXLtp = 1.0f * PI;

    glBegin(GL_TRIANGLE_FAN);///right wheel cover
    glColor3ub(31, 83, 88);


    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    carwheelXLr = 0.02275f;


    carwheelXLtp = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);///right wheel tier
    glColor3ub(0, 0, 0);

    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

    carwheelXLr = 0.01235416f;
    glBegin(GL_TRIANGLE_FAN);///right wheel
    glColor3ub(255, 255, 255);

    glVertex2f(carwheelXLp, carwheelXLq);
    for (c = 0;c <= carwheelXLtri; c++)
    {
        glVertex2f(carwheelXLp + (carwheelXLr * cos(c * carwheelXLtp / carwheelXLtri)),
            carwheelXLq + (carwheelXLr * sin(c * carwheelXLtp / carwheelXLtri)));
    }
    glEnd();

     int smokeXLtri = 40;
     GLfloat smokeXLp =-0.094875f;
     GLfloat smokeXLq = -0.627778f;
     GLfloat smokeXLr = 0.0143583f;
     GLfloat smokeXLtp = 2.0f * PI;



    glBegin(GL_TRIANGLE_FAN);///car smoke
        glColor4ub(200, 200, 200, 200);



    glVertex2f(smokeXLp, smokeXLq);
    for (c = 0;c <= smokeXLtri; c++)
    {
        glVertex2f(smokeXLp + (smokeXLr * cos(c * smokeXLtp / smokeXLtri)),
            smokeXLq + (smokeXLr * sin(c * smokeXLtp / smokeXLtri)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);///car smoke2
       glColor4ub(200, 200, 200, 150);
     smokeXLp =-0.119875f;
    smokeXLq = -0.627778f;
    smokeXLr = 0.0223583f;
    smokeXLtp = 2.0f * PI;

    glVertex2f(smokeXLp, smokeXLq);
    for (c = 0;c <= smokeXLtri; c++)
    {
        glVertex2f(smokeXLp + (smokeXLr * cos(c * smokeXLtp / smokeXLtri)),
            smokeXLq + (smokeXLr * sin(c * smokeXLtp / smokeXLtri)));
    }
    glEnd();

    glPushMatrix();
    glTranslatef(carSmokeposition, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);///car smoke2
       glColor4ub(200, 200, 200, 100);
     smokeXLp =-0.139875f;
    smokeXLq = -0.627778f;
    smokeXLr = 0.0223583f;
    smokeXLtp = 2.0f * PI;


    glVertex2f(smokeXLp, smokeXLq);
    for (c = 0;c <= smokeXLtri; c++)
    {
        glVertex2f(smokeXLp + (smokeXLr * cos(c * smokeXLtp / smokeXLtri)),
            smokeXLq + (smokeXLr * sin(c * smokeXLtp / smokeXLtri)));
    }
    glEnd();
    glPopMatrix();



    glPopMatrix();
}

void redLights()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;
    for(float f = 0.0f; f <= 2.0; f += 0.095)
    {
        glLineWidth(10.5);//////////////////// LIGHT BAR
        glBegin(GL_LINES);
        glColor3ub(139,0,0);
        glVertex2f(-1.0f + f,0.05f);
        glVertex2f(-1.0f + f,0.10f);
        glEnd();

        p1= -1.0f + f;  q1= 0.10f;  r1 = 0.015f; //// RED LIGHT circle
        tringle2=40;
        tp2 =2.0f * PI  ;
        glBegin (GL_TRIANGLE_FAN);
        glColor3ub (253,0,0);
        glVertex2f (p1,q1);
        for(i= 0;i<=tringle2; i++)
        {
            glVertex2f (
                        p1+(r1*cos(i*tp2/tringle2)),
                        q1+(r1*sin(i*tp2/tringle2))
                        );
        }
        if(light)
        {
            p1= -1.0f + f;  q1= 0.10f;  r1 = 0.030f; //// RED LIGHT circle
            tringle2=40;
            tp2 =2.0f * PI  ;
            glBegin (GL_TRIANGLE_FAN);
            glColor4ub (253,0,0,100);
            glVertex2f (p1,q1);
            for(i= 0;i<=tringle2; i++)
            {
                glVertex2f (
                            p1+(r1*cos(i*tp2/tringle2)),
                            q1+(r1*sin(i*tp2/tringle2))
                            );
            }
        }
        glEnd ();
    }
}

void railline()
{
    glBegin(GL_QUADS);
    glColor3ub(47, 79, 79); // Rail line er first deep gray step ta
    glVertex2f(-1.0f, -0.025f);
    glVertex2f(-1.0f, 0.05f);
    glVertex2f(1.0f, 0.05f);
    glVertex2f(1.0f, -0.025f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 215, 0); // Rail line er 2nd light gray step ta
    glVertex2f(-1.0f, -0.07f);
    glVertex2f(-1.0f, -0.025f);
    glVertex2f(1.0f, -0.025f);
    glVertex2f(1.0f, -0.07f);
    glEnd();

    ///////////////////////////////////// 1st left piller structure

    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er line first step up to down
    glVertex2f(-1.0f, -0.11f);
    glVertex2f(-1.0f, -0.065f);
    glVertex2f(-0.9f, -0.065f);
    glVertex2f(-0.9f, -0.11f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 20, 60); // left er bridge er line 2nd step up to down
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(-0.9f, -0.1f);
    glVertex2f(-0.9f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er line 3rd step up to down
    glVertex2f(-1.0f, -0.18f);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(-0.9f, -0.15f);
    glVertex2f(-0.9f, -0.18f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45); // left ar bridge er main lenth line light gray
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-1.0f, -0.18f);
    glVertex2f(-0.958f, -0.18f);
    glVertex2f(-0.958f, -0.7f);
    glEnd();




    ///////////////////////////////////// 2nd  from left side piller structure

    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er line first step up to down
    glVertex2f(-0.7f, -0.11f);
    glVertex2f(-0.7f, -0.065f);
    glVertex2f(-0.5f, -0.065f);
    glVertex2f(-0.5f, -0.11f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 20, 60); // left er bridge er line 2nd step up to down
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.7f, -0.1f);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(-0.5f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er line 3rd step up to down
    glVertex2f(-0.7f, -0.18f);
    glVertex2f(-0.7f, -0.15f);
    glVertex2f(-0.5f, -0.15f);
    glVertex2f(-0.5f, -0.18f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45); // left ar bridge er main lenth line light gray
    glVertex2f(-0.65f, -0.7f);
    glVertex2f(-0.65f, -0.18f);
    glVertex2f(-0.548f, -0.18f);
    glVertex2f(-0.548f, -0.7f);
    glEnd();

    //////////////////////////////////  3rd bridge piller from left structure


    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er piller first step up to down
    glVertex2f(-0.3f, -0.11f);
    glVertex2f(-0.3f, -0.065f);
    glVertex2f(-0.1f, -0.065f);
    glVertex2f(-0.1f, -0.11f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 20, 60); // left er bridge er piller 2nd step up to down
    glVertex2f(-0.3f, -0.15f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(-0.1f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er piller 3rd step up to down
    glVertex2f(-0.3f, -0.18f);
    glVertex2f(-0.3f, -0.15f);
    glVertex2f(-0.1f, -0.15f);
    glVertex2f(-0.1f, -0.18f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45); // left ar bridge er main lenth piller light gray
    glVertex2f(-0.25f, -0.7f);
    glVertex2f(-0.25f, -0.18f);
    glVertex2f(-0.148f, -0.18f);
    glVertex2f(-0.148f, -0.7f);
    glEnd();



    //////////////////////////////////  4th bridge piller  structure


    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er piller first step up to down
    glVertex2f(0.2f, -0.11f);
    glVertex2f(0.2f, -0.065f);
    glVertex2f(0.4f, -0.065f);
    glVertex2f(0.4f, -0.11f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 20, 60); // left er bridge er piller 2nd step up to down
    glVertex2f(0.2f, -0.15f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.4f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er piller 3rd step up to down
    glVertex2f(0.2f, -0.18f);
    glVertex2f(0.2f, -0.15f);
    glVertex2f(0.4f, -0.15f);
    glVertex2f(0.4f, -0.18f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45); // left ar bridge er main lenth piller light gray
    glVertex2f(0.25f, -0.7f);
    glVertex2f(0.25f, -0.18f);
    glVertex2f(0.348f, -0.18f);
    glVertex2f(0.348f, -0.7f);
    glEnd();



    //////////////////////////////////  4th bridge piller structure


    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er piller first step up to down
    glVertex2f(0.6f, -0.11f);
    glVertex2f(0.6f, -0.065f);
    glVertex2f(0.8f, -0.065f);
    glVertex2f(0.8f, -0.11f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 20, 60); // left er bridge er piller 2nd step up to down
    glVertex2f(0.6f, -0.15f);
    glVertex2f(0.6f, -0.1f);
    glVertex2f(0.8f, -0.1f);
    glVertex2f(0.8f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 0, 0); // left er bridge er piller 3rd step up to down
    glVertex2f(0.6f, -0.18f);
    glVertex2f(0.6f, -0.15f);
    glVertex2f(0.8f, -0.15f);
    glVertex2f(0.8f, -0.18f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45); // left ar bridge er main lenth piller light gray
    glVertex2f(0.65f, -0.7f);
    glVertex2f(0.65f, -0.18f);
    glVertex2f(0.748f, -0.18f);
    glVertex2f(0.748f, -0.7f);
    glEnd();
}

void greenGround()
{
    glBegin(GL_POLYGON);
	glColor3ub(60,179,113);
	glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glVertex2f(1.0f,-0.7);
    glVertex2f(-1.0f,-0.7f);
    glEnd();
}

void bush()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;
    p1=0.94f;  q1= -0.779f;  r1 = 0.08f; ////right side er park side design circle first
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (218,165,32);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


    p1=0.85f;  q1= -0.85f;  r1 = 0.08f; ////right side er park side design circle second
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (218,165,32);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


    p1=0.8f;  q1= -0.95f;  r1 = 0.08f; ////right side er park side design circle third
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (218,165,32);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


    p1=0.92f;  q1= -0.93f;  r1 = 0.11f; ////right side er park side design circle 4th
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (218,165,32);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();
}

void slipper()
{
    glLineWidth(3.5);

    glBegin(GL_LINES);
    glColor3ub(210,105,30);
    glVertex2f(0.40f,-0.80f);
    glVertex2f(0.44f, -0.80f);


    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(178,34,34);
    glVertex2f(0.40f,-0.83f);
    glVertex2f(0.44f, -0.83f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(178,34,34);
    glVertex2f(0.40f,-0.86f);
    glVertex2f(0.44f, -0.86f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(178,34,34);
    glVertex2f(0.40f,-0.89f);
    glVertex2f(0.44f, -0.89f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(178,34,34);
    glVertex2f(0.40f,-0.92f);
    glVertex2f(0.44f, -0.92f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(178,34,34);
    glVertex2f(0.40f,-0.95f);
    glVertex2f(0.44f, -0.95f);
    glEnd();


    glLineWidth(3.5);////////////////////slipper left  side
    glBegin(GL_LINES);
    glColor3ub(178,34,34);
    glVertex2f(0.40f,-0.798f);
    glVertex2f(0.40f, -0.952f);
    glEnd();
    glLineWidth(3.5);////////////////////slipper right side
    glBegin(GL_LINES);
    glColor3ub(178,34,34);
    glVertex2f(0.44f,-0.80f);
    glVertex2f(0.44f, -0.952f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(210,105,30); // main slipper box
    glVertex2f(0.40f, -0.80f);
    glVertex2f(0.44f, -0.80f);
    glVertex2f(0.50f, -0.95f);
    glVertex2f(0.46f, -0.95f);
    glEnd();
}

void boy1()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;
    glBegin(GL_QUADS);
    glColor3ub(255,255,0); // slipper er samner boy
    glVertex2f(0.52f, -0.96f);
    glVertex2f(0.52f, -0.91f);
    glVertex2f(0.54f,-0.91f);
    glVertex2f(0.54f, -0.96f);
    glEnd();

    glLineWidth(3.5);////////////////////left leg of left side boy
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(0.525f,-0.99f);
    glVertex2f(0.525f, -0.96f);
    glEnd();

    glLineWidth(3.5);////////////////////righ leg of left side boy
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(0.535f,-0.99f);
    glVertex2f(0.535f, -0.96f);
    glEnd();


    glLineWidth(3.5);////////////////////left hand for left side boy
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(0.52f,-0.915f);
    glVertex2f(0.505f, -0.935f);
    glEnd();

    glLineWidth(3.5);////////////////////right hand for left side boy
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(0.54f,-0.915f);
    glVertex2f(0.555f, -0.935f);
    glEnd();

    glLineWidth(9.5);////////////////////right man er neck
    glBegin(GL_LINES);
    glColor3ub(255,248,220);
    glVertex2f(0.525f,-0.90f);
    glVertex2f(0.535f, -0.89f);
    glEnd();

    p1=0.528f;  q1= -0.89f;  r1 = 0.015f; ////1st boy er matha
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (139,69,19);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
    glVertex2f (
                p1+(r1*cos(i*tp2/tringle2)),
                q1+(r1*sin(i*tp2/tringle2))
                );
    }
    glEnd ();

}

void boy2()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;

    glBegin(GL_QUADS);
      glColor3ub(255,0,0); // slipper er samner right last boy
      glVertex2f(0.57f, -0.96f);
      glVertex2f(0.57f, -0.91f);
      glVertex2f(0.59f,-0.91f);
      glVertex2f(0.59f, -0.96f);
   glEnd();

   glLineWidth(3.5);////////////////////left leg of right side boy
	glBegin(GL_LINES);
	glColor3ub(255,248,220);
	glVertex2f(0.575f,-0.99f);
	glVertex2f(0.575f, -0.96f);
	glEnd();

	glLineWidth(3.5);////////////////////right leg of right side boy
	glBegin(GL_LINES);
	glColor3ub(255,248,220);
	glVertex2f(0.585f,-0.99f);
	glVertex2f(0.585f, -0.96f);
	glEnd();



	 glLineWidth(3.5);////////////////////left hand for left side boy
	glBegin(GL_LINES);
	glColor3ub(255,248,220);
	glVertex2f(0.57f,-0.915f);
	glVertex2f(0.555f, -0.935f);
	glEnd();

	glLineWidth(3.5);////////////////////right hand for left side boy
	glBegin(GL_LINES);
	glColor3ub(255,248,220);
	glVertex2f(0.59f,-0.915f);
	glVertex2f(0.61f, -0.935f);
	glEnd();


	glLineWidth(9.5);////////////////////left man er neck
	glBegin(GL_LINES);
	glColor3ub(255,248,220);
	glVertex2f(0.579f,-0.91f);
	glVertex2f(0.582f, -0.89f);
	glEnd();

		 p1=0.578f;  q1= -0.89f;  r1 = 0.015f; ////2nd  boy er matha
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (210,105,30);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();
}

void bench()
{
    glBegin(GL_QUADS);
      glColor3ub(220,20,60); // bench main boshare jaigah
      glVertex2f(0.25f, -0.80f);
      glVertex2f(0.26f, -0.75f);
      glVertex2f(0.36,-0.75f);
      glVertex2f(0.35f, -0.80f);
   glEnd();

   glLineWidth(4.5);////////////////////bench right first leg
	glBegin(GL_LINES);
	glColor3ub(139,0,0);
	glVertex2f(0.348f,-0.80f);
	glVertex2f(0.348f, -0.84f);
	glEnd();

	 glLineWidth(4.5);////////////////////bench right last leg
	glBegin(GL_LINES);
	glColor3ub(139,0,0);
	glVertex2f(0.36f,-0.75f);
	glVertex2f(0.36f, -0.80f);
	glEnd();

	glLineWidth(4.5);////////////////////bench left first leg
	glBegin(GL_LINES);
	glColor3ub(139,0,0);
	glVertex2f(0.254f,-0.80f);
	glVertex2f(0.254f, -0.84f);
	glEnd();

	glLineWidth(4.5);////////////////////bench left last leg
	glBegin(GL_LINES);
	glColor3ub(139,0,0);
	glVertex2f(0.275f,-0.801f);
	glVertex2f(0.275f, -0.825f);
	glEnd();
}

void tree1()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;
    glLineWidth(10.5);//////////////////// treee brick
	glBegin(GL_LINES);
	glColor3ub(139,0,0);
	glVertex2f(-0.63f,-0.93f);
	glVertex2f(-0.63f, -1.0f);
	glEnd();

    p1=-0.63f;  q1= -0.9f;  r1 = 0.045f; ////nicher circle
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (128,128,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }

    glEnd ();


    p1=-0.63f;  q1= -0.85f;  r1 = 0.035f; ////middle
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (128,128,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


    p1=-0.63f;  q1= -0.80f;  r1 = 0.030f; ////middle
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (128,128,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();
}

void tree2()
{
    glLineWidth(10.5);//////////////////// treee brick
    glBegin(GL_LINES);
    glColor3ub(139,0,0);
    glVertex2f(-0.7f,-0.93f);
    glVertex2f(-0.7f, -1.0f);
    glEnd();



    glBegin(GL_TRIANGLES); // down tree
    glColor3ub(0,100,0);
    glVertex2f(-0.75f,-0.93f);
    glVertex2f(-0.70f,-0.84f);
    glVertex2f(-0.65f,-0.93f);
    glEnd();

    glBegin(GL_TRIANGLES); // middle tree
    glColor3ub(0,128,0);
    glVertex2f(-0.75f,-0.90f);
    glVertex2f(-0.70f,-0.80f);
    glVertex2f(-0.65f,-0.90f);
    glEnd();

    glBegin(GL_TRIANGLES); // first treee
    glColor3ub(0,100,0);
    glVertex2f(-0.75f,-0.865f);
    glVertex2f(-0.70f,-0.78f);
    glVertex2f(-0.65f,-0.865f);

    glEnd();
}

void tree3()
{
    glLineWidth(10.5);//////////////////// treee brick
    glBegin(GL_LINES);
    glColor3ub(139,0,0);
    glVertex2f(-0.55f,-0.93f);
    glVertex2f(-0.55f, -1.0f);
    glEnd();

    glBegin(GL_TRIANGLES); // down tree
    glColor3ub(0,100,0);
    glVertex2f(-0.6f,-0.93f);
    glVertex2f(-0.55f,-0.84f);
    glVertex2f(-0.50f,-0.93f);
    glEnd();

    glBegin(GL_TRIANGLES); // middle tree
    glColor3ub(0,128,0);
    glVertex2f(-0.60f,-0.90f);
    glVertex2f(-0.55f,-0.80f);
    glVertex2f(-0.50f,-0.90f);
    glEnd();

    glBegin(GL_TRIANGLES); // first treee
    glColor3ub(0,100,0);
    glVertex2f(-0.60f,-0.865f);
    glVertex2f(-0.55f,-0.78f);
    glVertex2f(-0.50f,-0.865f);

    glEnd();
}

void tree4()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;

/////////////////////////////////////////////////////////////////////////////////new treeee
glLineWidth(15.5); // brick

	glBegin(GL_LINES);
	glColor3ub(178,34,34);
	glVertex2f(0.66f,-1.0f);
	glVertex2f(0.66f, -0.80f);
glEnd();


 p1=0.62f;  q1= -0.85f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();
 p1=0.60f;  q1= -0.82f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

 p1=0.61f;  q1= -0.78f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

     p1=0.60f;  q1= -0.76f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();
 p1=0.64f;  q1= -0.74f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

     p1=0.66f;  q1= -0.74f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


     p1=0.68f;  q1= -0.74f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

     p1=0.70f;  q1= -0.76f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

     p1=0.72f;  q1= -0.77f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


        p1=0.69f;  q1= -0.79f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


        p1=0.71f;  q1= -0.79f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


        p1=0.72f;  q1= -0.83f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

        p1=0.70f;  q1= -0.86f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();



    p1=0.65f;  q1= -0.86f;  r1 = 0.038f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    p1=0.67f;  q1= -0.84f;  r1 = 0.067f; ////treee
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();
}

void goalposts()
{
    goalpost();
    glPushMatrix();//Tanbir
    glScalef(-1.0,1.0, 1.0);
    glTranslatef(0.2,0.0,0.0);
    goalpost();
    glPopMatrix();
}

void players()
{
    glPushMatrix();
    glTranslatef(0.0f, playerpos -0.04, 0.0f);
        player();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, -playerpos -0.04, 0.0f);
        glPushMatrix();
        glScalef(-1.0,1.0, 1.0);
        glTranslatef(0.2,0.0,0.0);
        player();
        glPopMatrix();
    glPopMatrix();
}

void football()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;
    glPushMatrix();
    glTranslatef(footballx,-0.09,0.0f);
    p1=-0.30f;  q1= -0.75f;  r1 = 0.022f; //// ground circle
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();
    glPopMatrix();
}

void footBallGround()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;
    p1=-0.09f;  q1= -0.84f;  r1 = 0.040f; //// ground circle
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,255);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    glLineWidth(3.5);//////////////////// left side er gorund black
	glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex2f(-0.44f,-0.995f);
	glVertex2f(-0.44f, -0.707f);
	glEnd();

    glLineWidth(3.5);///////////////// right side er gorund black
	glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex2f(0.24f,-0.995f);
	glVertex2f(0.24f, -0.707f);
	glEnd();


	glLineWidth(3.5);///////////////// uporer black line
	glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex2f(-0.44f,-0.71f);
	glVertex2f(0.24f, -0.71f);
	glEnd();


	glLineWidth(3.5);///////////////// nicher black line
	glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex2f(-0.44f,-0.99f);
	glVertex2f(0.24f, -0.99f);
	glEnd();

    glLineWidth(3.5);///////////////// majher black line
	glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex2f(-0.09f,-1.0f);
	glVertex2f(-0.09f, -0.7f);
	glEnd();
}

void flower()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;
    p1=0.88f;  q1= -0.84f;  r1 = 0.020f; ////Sun flower
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    p1=0.91f;  q1= -0.84f;  r1 = 0.015f; ////flower
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,0,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    p1=0.94f;  q1= -0.84f;  r1 = 0.020f; ////flower
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    p1=0.91f;  q1= -0.87f;  r1 = 0.020f; ////flower
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

     p1=0.91f;  q1= -0.81f;  r1 = 0.020f; ////Sun flower
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    p1=0.90f;  q1= -0.93f;  r1 = 0.018f; ////flower yellow
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

     p1=0.94f;  q1= -0.93f;  r1 = 0.018f; ////flower yellow
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


     p1=0.94f;  q1= -0.97f;  r1 = 0.018f; ////flower yellow
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

     p1=0.90f;  q1= -0.97f;  r1 = 0.018f; ////flower yellow
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

     p1=0.92f;  q1= -0.95f;  r1 = 0.018f; ////flower black
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,0,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

///////////////////////////////////////another flower


p1=0.78f;  q1= -0.95f;  r1 = 0.018f; ////flower yellow
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


    p1=0.84f;  q1= -0.95f;  r1 = 0.018f; ////flower yellow
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    p1=0.81f;  q1= -0.92f;  r1 = 0.018f; ////flower yellow
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


    p1=0.81f;  q1= -0.98f;  r1 = 0.018f; ////flower yellow
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255,255,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

 p1=0.81f;  q1= -0.95f;  r1 = 0.018f; ////flower black
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,0,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();
}

void bushtree()
{
    GLfloat p1, q1, r1, tp2 =2.0f * PI; int tringle2;
    int i;

    p1=-0.6f;  q1= -1.0f;  r1 = 0.045f; ////Tree er samner je circle kore tree kora oigulor code
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (34,139,34);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    p1=-0.7f;  q1= -1.0f;  r1 = 0.045f; ////////// Tree er samner je circle kore tree kora oigulor code
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (34,139,34);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

     p1=-0.65f;  q1= -1.0f;  r1 = 0.045f; ////////////tree circle design
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,100,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    p1=-0.55f;  q1= -1.0f;  r1 = 0.045f; ////tree circle design
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,100,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();

    p1=-0.75f;  q1= -1.0f;  r1 = 0.045f; ////tree circle design
    tringle2=40;
    tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (0,100,0);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();
}

void mosque()
{
    glBegin(GL_QUADS);///domed2
    glColor3ub(220,197,153);
    glVertex2f(-0.285417f,-0.474074f);
    glVertex2f(-0.260417f,-0.472222f);
    glVertex2f(-0.260417f,-0.107407f);
    glVertex2f(-0.285417f,-0.107407f);
    glEnd();

    glLineWidth(4.0);
    float x = -0.061112;


    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.284375f,-0.405556f);
    glVertex2f(-0.259375f ,-0.405556f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.284375f,-0.405556f+0.061112);
    glVertex2f(-0.259375f ,-0.405556f+0.061112);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.284375f,-0.405556f+0.061112+0.061112);
    glVertex2f(-0.259375f ,-0.405556f+0.061112+0.061112);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.284375f,-0.405556f+0.061112+0.061112);
    glVertex2f(-0.259375f ,-0.405556f+0.061112+0.061112);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.284375f,-0.405556f+0.061112+0.061112+0.061112);
    glVertex2f(-0.259375f ,-0.405556f+0.061112+0.061112+0.061112);
    glEnd();


    int c;///dome
    int mosqueXLtri = 40;
    GLfloat mosqueXLp =-0.095975f;
    GLfloat  mosqueXLq = -0.629778f;
    GLfloat  mosqueXLr = 0.0143583f;
    GLfloat mosqueXLtp = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN); ///dome1
    glColor3ub(100, 206,188);
    mosqueXLp =  -0.449658f;
    mosqueXLq = -0.287185f;
    mosqueXLr = 0.0625f;
    mosqueXLtp = 1.0f * PI;

    glVertex2f(mosqueXLp, mosqueXLq);
    for (c = 0;c <= mosqueXLtri; c++)
    {
    glVertex2f(mosqueXLp + (mosqueXLr * cos(c * mosqueXLtp / mosqueXLtri)),
    mosqueXLq + (mosqueXLr * sin(c * mosqueXLtp / mosqueXLtri)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN); ///dome1
    glColor3ub(100, 206,188);
    mosqueXLp =  -0.273958;
    mosqueXLq = -0.111111f;
    mosqueXLr = 0.013542;
    mosqueXLtp = 1.0f * PI;

    glVertex2f(mosqueXLp, mosqueXLq);
    for (c = 0;c <= mosqueXLtri; c++)
    {
    glVertex2f(mosqueXLp + (mosqueXLr * cos(c * mosqueXLtp / mosqueXLtri)),
    mosqueXLq + (mosqueXLr * sin(c * mosqueXLtp / mosqueXLtri)));
    }
    glEnd();
    glBegin(GL_QUADS);///main hall
    glColor3ub(220,197,153);
    glVertex2f(-0.536458f,-0.472222f);
    glVertex2f(-0.277083f,-0.472222f);
    glVertex2f(-0.277083f,-0.344444f);
    glVertex2f(-0.536458f,-0.344444f);
    glEnd();


    glBegin(GL_QUADS);///domed
    glColor3ub(220,197,153);
    glVertex2f(-0.511458f,-0.288889f);
    glVertex2f(-0.390625f,-0.288889f);
    glVertex2f(-0.390625f,-0.344593f);
    glVertex2f(-0.511458f,-0.344593f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); ///dome2
    glColor3ub(100, 206,188);
    mosqueXLp =  -0.327883f;
    mosqueXLq = -0.31819f;
    mosqueXLr = 0.032292f;
    mosqueXLtp = 1.0f * PI;

    glVertex2f(mosqueXLp, mosqueXLq);
    for (c = 0;c <= mosqueXLtri; c++)
    {
    glVertex2f(mosqueXLp + (mosqueXLr * cos(c * mosqueXLtp / mosqueXLtri)),
    mosqueXLq + (mosqueXLr * sin(c * mosqueXLtp / mosqueXLtri)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN); ///
    glColor3ub(209, 168,106);
    mosqueXLp = -0.45f;
    mosqueXLq = -0.21333f;
    mosqueXLr = 0.009f;
    mosqueXLtp = 2.0f * PI;

    glVertex2f(mosqueXLp, mosqueXLq);
    for (c = 0;c <= mosqueXLtri; c++)
    {
    glVertex2f(mosqueXLp + (mosqueXLr * cos(c * mosqueXLtp / mosqueXLtri)),
    mosqueXLq + (mosqueXLr * sin(c * mosqueXLtp / mosqueXLtri)));
    }
    glEnd();
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.45f,-0.21333f);
    glVertex2f(-0.45f,-0.2f);
    glEnd();

    glBegin(GL_QUADS);///domed2
    glColor3ub(220,197,153);
    glVertex2f(-0.361458f,-0.318519f);
    glVertex2f(-0.295833f,-0.318519f);
    glVertex2f(-0.295833f,-0.342593f);
    glVertex2f(-0.361458f,-0.342593f);
    glEnd();

    glBegin(GL_QUADS);///lower ground
    glColor3ub(83,144,126);
    glVertex2f(-0.536458f,-0.464815f);
    glVertex2f(-0.275f,-0.464815f);
    glVertex2f(-0.275f,-0.474074f);
    glVertex2f(-0.536458f,-0.474074f);

    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.538542f,-0.344444f);
    glVertex2f(-0.275f,-0.344444f);
    glEnd();
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.491667f,-0.372222f);
    glVertex2f(-0.321875f,-0.372222f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.486458f,-0.374074f);
    glVertex2f(-0.486458f,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.486458f,-0.427778f);
    glVertex2f(-0.486458f,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.477083,-0.374074f);
    glVertex2f(-0.477083,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.477083,-0.427778f);
    glVertex2f(-0.477083,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.477083,-0.374074f);
    glVertex2f(-0.477083,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.477083,-0.427778f);
    glVertex2f(-0.477083,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.440625,-0.374074f);
    glVertex2f(-0.440625,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.440625,-0.427778f);
    glVertex2f(-0.440625,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.432292,-0.374074f);
    glVertex2f(-0.432292,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.432292,-0.427778f);
    glVertex2f(-0.432292,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.371875,-0.374074f);
    glVertex2f(-0.371875,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.371875,-0.427778f);
    glVertex2f(-0.371875,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.371875,-0.374074f);
    glVertex2f(-0.371875,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.371875,-0.427778f);
    glVertex2f(-0.371875,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.38125,-0.374074f);
    glVertex2f(-0.38125,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.38125,-0.427778f);
    glVertex2f(-0.38125,-0.455556f);
    glEnd();

    ///

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.335417,-0.374074f);
    glVertex2f(-0.335417,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.335417,-0.427778f);
    glVertex2f(-0.335417,-0.455556f);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3ub(83,144,126);
    glVertex2f(-0.327083,-0.374074f);
    glVertex2f(-0.327083,-0.427778f);
    glEnd();
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3ub(235,165,79);
    glVertex2f(-0.327083,-0.427778f);
    glVertex2f(-0.327083,-0.455556f);
    glEnd();

    glBegin(GL_QUADS); ///pillar ground
    glColor3ub(117,80,62);
    glVertex2f(-0.491667f,-0.453704f);
    glVertex2f(-0.429167f,-0.453704f);
    glVertex2f(-0.429167f,-0.47037f);
    glVertex2f(-0.491667f,-0.47037f);
    glEnd();

    glBegin(GL_QUADS); ///pillar ground
    glColor3ub(117,80,62);
    glVertex2f(-0.384375,-0.453704f);
    glVertex2f(-0.322917,-0.453704f);
    glVertex2f(-0.322917,-0.47037f);
    glVertex2f(-0.384375,-0.47037f);

    glEnd();

    glBegin(GL_QUADS); ///mosque window lefts
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.530208f,-0.451852f);
    glVertex2f(-0.51875f,-0.451852f);
    glVertex2f(-0.51875f,-0.388889f);
    glVertex2f(-0.530208f,-0.388889f);

    glEnd();
    glBegin(GL_QUADS); ///mosque window lefts
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.509375f,-0.451852f);
    glVertex2f(-0.498958f,-0.451852f);
    glVertex2f(-0.498958f,-0.392593f);
    glVertex2f(-0.509375f,-0.392593f);
    glEnd();

    glBegin(GL_QUADS); ///mosque window
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.313542f,-0.451852f);
    glVertex2f(-0.303125f,-0.451852f);
    glVertex2f(-0.303125f,-0.396296f);
    glVertex2f(-0.313542f,-0.396296f);
    glEnd();
    glBegin(GL_QUADS); ///mosque window lefts
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.530208f+0.235416f,-0.451852f);
    glVertex2f(-0.51875f+0.235416f,-0.451852f);
    glVertex2f(-0.51875f+0.235416f,-0.388889f);
    glVertex2f(-0.530208f+0.235416f,-0.388889f);
    glEnd();


    glBegin(GL_QUADS); ///mosque door lefts
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.470833f,-0.451852f);
    glVertex2f(-0.460417f,-0.451852f);
    glVertex2f(-0.460417f,-0.388889f);
    glVertex2f(-0.470833f,-0.388889f);

    glEnd();

    glBegin(GL_QUADS); ///mosque door lefts
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.470833f+0.013541,-0.451852f);
    glVertex2f(-0.460417f+0.013541,-0.451852f);
    glVertex2f(-0.460417f+0.013541,-0.388889f);
    glVertex2f(-0.470833f+0.013541,-0.388889f);

    glEnd();

    glBegin(GL_QUADS); ///mosque door lefts
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.470833f+(0.103125),-0.451852f);
    glVertex2f(-0.460417f+0.103125,-0.451852f);
    glVertex2f(-0.460417f+0.103125,-0.388889f);
    glVertex2f(-0.470833f+0.103125,-0.388889f);

    glEnd();

    glBegin(GL_QUADS); ///mosque door lefts
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.470833f+(0.103125+0.013541),-0.451852f);
    glVertex2f(-0.460417f+0.103125+0.013541,-0.451852f);
    glVertex2f(-0.460417f+0.103125+0.013541,-0.388889f);
    glVertex2f(-0.470833f+0.103125+0.013541,-0.388889f);

    glEnd();
    glBegin(GL_QUADS); ///mosque door lefts
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.428125f,-0.451852f);
    glVertex2f(-0.385417f,-0.451852f);
    glVertex2f(-0.385417f,-0.409259f);
    glVertex2f(-0.428125f,-0.409259f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.428125f,-0.409259f);
    glVertex2f(-0.41875f,-0.387037f);
    glVertex2f(-0.409375f,-0.409259f);
    glEnd();
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3ub(205,193,169);
    glVertex2f(-0.40625f,-0.381481f);
    glVertex2f(-0.40625f,-0.451852f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.428125f+0.026042,-0.409259f);
    glVertex2f(-0.41875f+0.026042,-0.387037f);
    glVertex2f(-0.409375f+0.026042,-0.409259f);
    glEnd();


     x = 0.019792;
    for(int i=0; i<=5;i++){
    glBegin(GL_TRIANGLES);
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.50625f+x*i,-0.340741f);
    glVertex2f(-0.497917f+x*i,-0.294444f);
    glVertex2f(-0.490625f+x*i,-0.340741f);
    glEnd();

    }
    x=0.010416;
    for(int i=0; i<=15;i++){
    glBegin(GL_TRIANGLES);
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.486458f+x*i,-0.366667f);
    glVertex2f(-0.484375f+x*i,-0.348148f);
    glVertex2f(-0.480208f+x*i,-0.366667f);
    glEnd();

    }
    for(int i=0; i<=5;i++){
    glBegin(GL_TRIANGLES);
    glColor3ub(70,59,65);
    if(light){glColor3ub(255, 255, 153);}
    glVertex2f(-0.359375f+x*i,-0.338889f);
    glVertex2f(-0.35625f+x*i,-0.322222f);
    glVertex2f(-0.351042f+x*i,-0.338889f);
    glEnd();

    }
}

void bakery()
{
    glBegin(GL_POLYGON); ///bakery floor roof
    glColor3ub(255, 226, 160);
    glVertex2f(-0.89375f,-0.244444f);
    glVertex2f(-0.708333f,-0.244444f);
    glVertex2f(-0.708333f,-0.259259f);
    glVertex2f(-0.89375f,-0.259259f);
    glEnd();
    glBegin(GL_POLYGON); ///bakery floor roof
    glColor3ub(255, 211, 108);
    glVertex2f(-0.89375f,-0.259259f);
    glVertex2f(-0.708333f,-0.259259f);
    glVertex2f(-0.716667f,-0.268519f);
    glVertex2f(-0.882292f,-0.268519f);
    glEnd();

    glBegin(GL_POLYGON); ///bakery shop
    glColor3ub(250, 179, 91);
    glVertex2f(-0.882292f,-0.268519f);
    glVertex2f(-0.716667f,-0.268519f);
    glVertex2f(-0.716667f,-0.468518f);
    glVertex2f(-0.882292f,-0.468518f);
    glEnd();

     glBegin(GL_POLYGON); ///bakery floor bound
    glColor3ub(141, 72, 30);
    glVertex2f(-0.889583f,-0.427778f);
    glVertex2f(-0.714583f,-0.427778f);
    glVertex2f(-0.714583f,-0.49163f);
    glVertex2f(-0.889583f,-0.49163f);
    glEnd();

    glBegin(GL_POLYGON); ///bakery window
    glColor3ub(193, 241,251);
    glVertex2f(-0.876042f,-0.324074f);
    glVertex2f(-0.779167f,-0.324074f);
    glVertex2f(-0.779167f,-0.412963f);
    glVertex2f(-0.876042f,-0.412963f);
    glEnd();

    glBegin(GL_POLYGON); ///bakery window shade
    glColor3ub(238, 94,31);
    glVertex2f(-0.876042f,-0.298148f);
    glVertex2f(-0.778125f,-0.298148f);
    glVertex2f(-0.772917f,-0.333333f);
    glVertex2f(-0.880208f,-0.333333f);
    glEnd();

    glLineWidth(3.5);///bakery window bar
        glBegin(GL_LINES);
        glColor3ub(87,109,120);
        glVertex2f(-0.873958f,-0.359259f);
        glVertex2f(-0.78125f,-0.359259f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(87,109,120);
        glVertex2f(-0.873958f,-0.381481f);
        glVertex2f(-0.78125f,-0.381481f);
        glEnd();

    glBegin(GL_POLYGON); ///bakery door
    glColor3ub(238, 94,31);
    glVertex2f(-0.766667f,-0.327778f);
    glVertex2f(-0.729167f,-0.327778f);
    glVertex2f(-0.729167f,-0.461111f);
    glVertex2f(-0.766667f,-0.461111f);

    glEnd();
    glBegin(GL_POLYGON); ///bakery door window
    glColor3ub(132, 174,162);
    glVertex2f(-0.761458f,-0.342593f);
    glVertex2f(-0.734375f,-0.342593f);
    glVertex2f(-0.734375f,-0.405556f);
    glVertex2f(-0.761458f,-0.405556f);

    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
        glColor3ub(113,89,62);
        glVertex2f(-0.746875f,-0.342593f);
        glVertex2f(-0.746875f,-0.405556f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(113,89,62);
        glVertex2f(-0.761375f,-0.372222f);
        glVertex2f(-0.734375f,-0.372222f);
        glEnd();

        glLineWidth(3.0);
    glBegin(GL_LINES);
        glColor3ub(250, 179, 91);
        glVertex2f(-0.759375f,-0.411111f);
        glVertex2f(-0.759375f,-0.425926f);
        glEnd();



     glBegin(GL_POLYGON); ///bakery garden
    glColor3ub(145, 157,59);
    glVertex2f(-0.878125f,-0.468518f);
    glVertex2f(-0.878125f,-0.464815f);
    glVertex2f(-0.880208f,-0.446296f);
    glVertex2f(-0.880208f,-0.446296f);
    glVertex2f(-0.871875f,-0.431481f);
    glVertex2f(-0.860417f,-0.42037f);
    glVertex2f(-0.807292f,-0.438889f);
    glVertex2f(-0.798958f,-0.425926f);
    glVertex2f(-0.779167f,-0.462963f);
    glVertex2f(-0.777083f,-0.47037f);
    glEnd();
    glBegin(GL_POLYGON); ///bakery garden tub
    glColor3ub(250, 209,153);
    glVertex2f(-0.88125f,-0.466667f);
    glVertex2f(-0.776042f,-0.466667f);
    glVertex2f(-0.776042f,-0.487037f);
    glVertex2f(-0.88125f,-0.487037f);
    glEnd();

    glBegin(GL_POLYGON); ///bakery top
    glColor3ub(242, 162,77);
    glVertex2f(-0.883333f,-0.237037f);
    glVertex2f(-0.71875f,-0.237037f);
    glVertex2f(-0.71875f,-0.181481f);
    glVertex2f(-0.883333f,-0.181481f);
    glEnd();
}

void footpath()
{
    int r=44;
    int g=44;
    int b=44;

    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(131, 131, 131);
    glVertex2f(1.0f, -0.45f);
    glVertex2f(-1.0f, -0.45f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(r, g, b);
    glVertex2f(-1.0f, -0.52f);
    glVertex2f(-0.9f, -0.52f);
    glVertex2f(-0.9f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(r, g, b);
    glVertex2f(-0.8f, -0.52f);
    glVertex2f(-0.7f, -0.52f);
    glVertex2f(-0.7f, -0.5f);
    glVertex2f(-0.8f, -0.5f);
    glEnd();

     glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(r, g, b);
    glVertex2f(-0.6f, -0.52f);
    glVertex2f(-0.5f, -0.52f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.6f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(r, g, b);
    glVertex2f(-0.4f, -0.52f);
    glVertex2f(-0.3f, -0.52f);
    glVertex2f(-0.3f, -0.5f);
    glVertex2f(-0.4f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(r, g, b);
    glVertex2f(-0.2f, -0.52f);
    glVertex2f(-0.1f, -0.52f);
    glVertex2f(-0.1f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(r, g, b);
    glVertex2f(0.0f, -0.52f);
    glVertex2f(0.1f, -0.52f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.0f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(r, g, b);

    glVertex2f(0.2f, -0.52f);
    glVertex2f(0.3f, -0.52f);
    glVertex2f(0.3f, -0.5f);
    glVertex2f(0.2f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(r, g, b);

    glVertex2f(0.4f, -0.52f);
    glVertex2f(0.5f, -0.52f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.4f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(r, g, b);

    glVertex2f(0.6f, -0.52f);
    glVertex2f(0.7f, -0.52f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.6f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor3ub(r, g, b);

    glVertex2f(0.8f, -0.52f);
    glVertex2f(0.9f, -0.52f);
    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glEnd();
}

void night_filter()
{
    glBegin(GL_POLYGON); ///footpath            //HASAN, MD. RAKIBUL
    glColor4ub(0, 0, 0, 50);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f,-1.0f);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(-1.0f,1.0f);
    glEnd();
}

void streetLights()
{
    int smokeXLtri = 40;
    GLfloat smokeXLp, smokeXLq, smokeXLr, smokeXLtp;

    float x =0.33125;
    for (int i = 0; i<=5;i++ ){
    glBegin(GL_POLYGON); ///
    glColor3ub(95, 95, 95);
    glVertex2f(0.830208-x*i, -0.7f);
    glVertex2f(0.857292f-x*i, -0.7f);
    glVertex2f(0.851042f-x*i,-0.675926f);
    glVertex2f(0.833333f-x*i,-0.675926f);
    glEnd();


    glLineWidth(4.5);
    glBegin(GL_LINES); //
    glColor3ub(95, 95, 95);
    glVertex2f(0.842708f-x*i,-0.674707f);
    glVertex2f(0.842708f-x*i,-0.414111f);
    glEnd();
    glLineWidth(2.5);

    glBegin(GL_LINES); //
    glColor3ub(0, 0, 0);
    glVertex2f(0.842708f-x*i,-0.414111f);
    glVertex2f(0.847917f-x*i,-0.381481f);
    glEnd();

    glBegin(GL_LINES); //
    glColor3ub(0, 0, 0);
    glVertex2f(0.842708f-x*i,-0.414111f);
    glVertex2f(0.839583f-x*i,-0.381481f);
    glEnd();

    glBegin(GL_LINES); //
    glColor3ub(0, 0, 0);
    glVertex2f(0.847917f-x*i,-0.381481f);
    glVertex2f(0.866667f-x*i,-0.381481f);
    glEnd();

    glBegin(GL_LINES); //
    glColor3ub(0, 0, 0);
    glVertex2f(0.866667f-x*i,-0.381481f);
    glVertex2f(0.86875f-x*i,-0.396296f);
    glEnd();

    glBegin(GL_LINES); //
    glColor3ub(0, 0, 0);
    glVertex2f(0.842708f-x*i,-0.414111f);
    glVertex2f(0.839583f-x*i,-0.381481f);
    glVertex2f(0.822917f-x*i,-0.381481f);
    glEnd();

    glBegin(GL_LINES); //
    glColor3ub(0, 0, 0);
    glVertex2f(0.839583f-x*i,-0.381481f);
    glVertex2f(0.822917f-x*i,-0.381481f);
    glEnd();

    glBegin(GL_LINES); //
    glColor3ub(0, 0, 0);
    glVertex2f(0.822917f-x*i,-0.381481f);
    glVertex2f(0.81875f-x*i,-0.396296f);
    glEnd();

    glBegin(GL_LINES); //
    glColor3ub(0, 0, 0);
    glVertex2f(0.810417f-x*i,-0.398148f);
    glVertex2f(0.826042f-x*i,-0.398148f);
    glEnd();

        glBegin(GL_LINES); //
    glColor3ub(0, 0, 0);
    glVertex2f(0.810417f+0.052083-x*i,-0.398148f);
    glVertex2f(0.826042f+0.052083-x*i,-0.398148f);
    glEnd();


     glBegin(GL_TRIANGLE_FAN);///street light left
      glColor4ub(255, 201, 14, 200);
     smokeXLp = 0.81875f-x*i;
    smokeXLq = -0.416519f;
    smokeXLr = 0.016f;
    smokeXLtp = 2.0f * PI;


    glVertex2f(smokeXLp, smokeXLq);
    for (int c = 0;c <= smokeXLtri; c++)
    {
        glVertex2f(smokeXLp + (smokeXLr * cos(c * smokeXLtp / smokeXLtri)),
            smokeXLq + (smokeXLr * sin(c * smokeXLtp / smokeXLtri)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);///street light left
      glColor4ub(255, 201, 14, 200);
     smokeXLp = 0.81875f+0.052083-x*i;
    smokeXLq = -0.416519f;
    smokeXLr = 0.016f;
    smokeXLtp = 2.0f * PI;

    glVertex2f(smokeXLp, smokeXLq);
    for (int c = 0;c <= smokeXLtri; c++)
    {
        glVertex2f(smokeXLp + (smokeXLr * cos(c * smokeXLtp / smokeXLtri)),
            smokeXLq + (smokeXLr * sin(c * smokeXLtp / smokeXLtri)));
    }
    glEnd();

    if(light)
    {
    glBegin(GL_TRIANGLES); // right side er triangle
    glColor3ub(0,139,139);
    glColor4ub(255, 201, 14, 150);
    glVertex2f(0.763542f-x*i,-0.683333f);
    glVertex2f(0.815625f-x*i,-0.446296f);
    glVertex2f(0.871875f-x*i,-0.683333f);

    glEnd();
    glBegin(GL_TRIANGLES); // right side er triangle
    glColor3ub(0,139,139);
    glColor4ub(255, 201, 14, 150);
    glVertex2f(0.815625f-x*i,-0.683333f);
    glVertex2f(0.867708f-x*i,-0.446296f);
    glVertex2f(0.928125f-x*i,-0.683333f);
    }


    glEnd();

    }
}



void day()
{
    //SKY......................................
    sky();

    //SUN......................................
    sun();

    //RIVER.................................
    river();

    //Beach
    beach();

    //Clouds................................
    cloud();

    //YACHT...................................
    yacht();

    //BUILDING 5 FROM RIGHT...................
    building5();

    //Building 4 FROM RIGHT...................
    building4();

    //Building 3 FROM RIGHT...................
    building3();

    //Building 2 from right side................
    building2();

    //Building 1 from right side.
    building1();

    //Station Roof and back...................
    stationRB();

    //Road....................................
    road();

    //Footpath
    footpath();

    //Bakery
    bakery();

    //MOSQUE.................................
    mosque();

    //HUMAN 5................................
    human5();

    //HUMAN 3................................
    human3();

    //HUMAN 4................................
    human4();

    //Escalator
    escalator();

    //Bus Stop................................
    busstop();

    //HUMAN 1.................................
    human1();

    //HUMAN 2.................................
    human2();


    //BUS.....................................
    bus();

    //Car.....................................
    car();
    car2();

    //Street Lights
    streetLights();

    //Train...................................
    train();

    //Station Front Pillars...................
    stationFP();

    //Red Lights..............................
    redLights();

    //Rail-Line..............................
    railline();

    //Green Ground...........................
    greenGround();

    //Fan or Windmill.........................
    fan();

    //Bush....................................
    bush();

    //Slipper.................................
    slipper();

    //Boy 1 // Left One beside the slipper...
    boy1();

    //Boy 2 // Right One beside the slipper..
    boy2();

    //Bench Park.............................
    bench();

    //Middle Tree with is draw by circle...
    tree1();

    //Left Tree...............................
    tree2();

    //Right Tree.................................
    tree3();

    tree4();

    //Bush under tree
    bushtree();

    //SUNFLOWER
    flower();

    //FOOTBALL GROUND
    footBallGround();

    //Football
    football();

    //Players
    players();

    //GOAL POSTS
    goalposts();
}

void night()
{
    //NIGHT SKY......................................
    nightSky();

    //MOON......................................
    moon();

    //RIVER.................................
    river();

    //Beach.................................
    beach();

    //Clouds................................
    cloud();

    //YACHT...................................
    yacht();

    //BUILDING 5 FROM RIGHT...................
    building5();

    //Building 4 FROM RIGHT...................
    building4();

    //Building 3 FROM RIGHT...................
    building3();

    //Building 2 from right side................
    building2();

    //Building 1 from right side.
    building1();

    //Station Roof and back...................
    stationRB();

    //Road....................................
    road();

    //Footpath
    footpath();

    //Bakery
    bakery();

    //MOSQUE.................................
    mosque();

    //HUMAN 5................................
    human5();

    //HUMAN 3................................
    human3();

    //HUMAN 4................................
    human4();

    //Escalator
    escalator();

    //Bus Stop................................
    busstop();

    //HUMAN 1.................................
    human1();

    //HUMAN 2.................................
    human2();


    //BUS.....................................
    bus();

    //Car.....................................
    car();
    car2();

    //Street Lights
    streetLights();

    //Train...................................
    train();

    //Station Front Pillars...................
    stationFP();

    //Red Lights..............................
    redLights();

    //Rail-Line..............................
    railline();

    //Green Ground...........................
    greenGround();

    //Fan or Windmill.........................
    fan();

    //Bush....................................
    bush();

    //Slipper.................................
    slipper();

    //Boy 1 // Left One beside the slipper...
    //boy1();

    //Boy 2 // Right One beside the slipper..
    //boy2();

    //Bench Park.............................
    bench();

    //Middle Tree with is draw by circle...
    tree1();

    //Left Tree...............................
    tree2();

    //Right Tree.................................
    tree3();

    tree4();

    //Bush under tree
    bushtree();

    //SUNFLOWER
    flower();

    //FOOTBALL GROUND
    footBallGround();

    //Football
    footballx = 0;
    football();

    //Players
    //players();

    //GOAL POSTS
    goalposts();

    night_filter();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    switch (time)
    {
    case 1:
        day();
        break;
    case 2:
        //evening();
        break;
    case 3:
        night();
        break;
    }
    glFlush();
}

void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        //speed += 0.1f;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        //speed -= 0.1f;
    }
    glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y) {
    switch (key)
    {
    case 'd':
        time = 1;
        light = false;
        break;
    case 'f':
        light = !light;
        break;
    case 'n':
        time = 3;
        light = true;
        break;
    case '0':
        exit(0);
        break;
    glutPostRedisplay();
    }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Metro Rail Station");
    glutFullScreen();
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}
