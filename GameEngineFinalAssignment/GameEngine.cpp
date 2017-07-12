//
//  helloOpenGL.cpp
//  Hello World
//
//  Created by Mr Yoshine on 01/10/2014.
//  Copyright (c) 2014 Yoshine LTD. All rights reserved.
//
#ifdef WIN32
#include <GL/gl.h>
#include <GL/glu.h>
#include "freeglut.h"
#include <iostream>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>
#include <iostream>
#endif

#include "GameEngine.h"

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("GameEngineFinalAssignment");
    
    
    glutDisplayFunc(renderScene);
    glutIdleFunc(update);
    
    setupRC();
    
    glutMainLoop();
    
    return 0;
}

void setupRC(void)
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat diffuseMaterial[4] = { 0.5, 0.5, 0.5, 1.0 };
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 5.0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    
    glutSpecialFunc(specialKeys);
    
    model = new AdvancedModel(1);
    
    reset();
    
    gcg = new GroundColitionGenorator(particles);
    gfg = new GravityForceGenorator(particles,ver3f(0.0, -0.918, 0.0));
    ptp = new PToPColitionGenorator(particles);
    
}

//Game Loop
void renderScene(void)
{
    /*
     * LEFT VIEW PORT
     */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, glutGet(GLUT_WINDOW_WIDTH)/glutGet(GLUT_WINDOW_HEIGHT), 1, 2000);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    eyeX = verX+dist*sin(rotX*(GL_PI/180))*cos(rotY*(GL_PI/180));
    eyeY = verY+dist*sin(rotY*(GL_PI/180));
    eyeZ = verZ+dist*cos(rotX*(GL_PI/180))*cos(rotY*(GL_PI/180));
    
    gluLookAt( eyeX, eyeY, eyeZ,
              verX, verY, verZ,
              0.0, dist*cos(rotY*(GL_PI/180)), 0.0);
    
    if(multiView)
    {
        glViewport(0, glutGet(GLUT_WINDOW_HEIGHT)/2, glutGet(GLUT_WINDOW_WIDTH)/2 , glutGet(GLUT_WINDOW_HEIGHT)/2);
        (mode == 1) ? glBegin(GL_TRIANGLES):glBegin(GL_LINE_STRIP);
        model->render(mode);
        glEnd();
        glViewport(glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_HEIGHT)/2, glutGet(GLUT_WINDOW_WIDTH)/2 , glutGet(GLUT_WINDOW_HEIGHT)/2);
        glRotatef(90, 0.0, 1.0, 0.0);
        (mode == 1) ? glBegin(GL_TRIANGLES):glBegin(GL_LINE_STRIP);
        model->render(mode);
        glEnd();
        glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH)/2 , glutGet(GLUT_WINDOW_HEIGHT)/2);
        glRotatef(180, 0.0, 1.0, 0.0);
        (mode == 1) ? glBegin(GL_TRIANGLES):glBegin(GL_LINE_STRIP);
        model->render(mode);
        glEnd();
        glViewport(glutGet(GLUT_WINDOW_WIDTH)/2, 0, glutGet(GLUT_WINDOW_WIDTH)/2 , glutGet(GLUT_WINDOW_HEIGHT)/2);
        glRotatef(90, 1.0, 0.0, 0.0);
        (mode == 1) ? glBegin(GL_TRIANGLES):glBegin(GL_LINE_STRIP);
        model->render(mode);
        glEnd();
    }else if (demoMode==1 ||demoMode==2||demoMode==3 ){
        glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH) , glutGet(GLUT_WINDOW_HEIGHT));
        for(int i = 0; i < particles.size(); i++)
        {
            glColor3f(0, 255, 0);
            particles[i].render();
        }
        floor();
    }else  {
        glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH) , glutGet(GLUT_WINDOW_HEIGHT));
        (mode == 1) ? glBegin(GL_TRIANGLES):glBegin(GL_LINE_STRIP);
        model->render(mode);
        glEnd();
        
    }
    
    glFlush();
    glutSwapBuffers();
}
void update(void)
{
    //Update all
    
    float startTime = glutGet(GLUT_ELAPSED_TIME);
    float dt = startTime - oldStartTime;
    oldStartTime = startTime;
    if(demoMode == 1)
    {
        for(int i = 0; i < particles.size(); i++)
        {
            particles[i].update(dt);
        }
        for(int i = 0; i < aecg.size(); i++)
        {
            aecg[i].resolve();
        }
        gcg->resolve();
        ptp->resolve();
        gfg->applyForce(dt);
    } else if (demoMode==2||demoMode==3){
        for(int i = 0; i < particles.size(); i++)
        {
            particles[i].update(dt);
        }
        gcg->resolve();
        ptp->resolve();
        gfg->applyForce(dt);
    }
    
}
void floor()
{
    glBegin(GL_QUADS);
    glColor3f(10, 10, 10);
    
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(100.0, 0.0, -100.0);
    glVertex3f(-100.0, 0.0, -100.0);
    glVertex3f(-100.0, 0.0, 100.0);
    glEnd();
}

void reset()
{
    particles.clear();
    aecg.clear();
    switch (demoMode) {
        case 1:
            for (int i = 0; i < 4;i++)
            {
                Particle p = (i == 0) ? Particle(-9+(i*2), 8.0, 0.0, 1):Particle(-4+(i*2), 3.0, 0.0, 1);
                particles.push_back(p);
            }
            for (int i = 0; i < particles.size();i++)
            {
                AnchoredEqualityConstrainGenorator anchor = (i == 0) ? AnchoredEqualityConstrainGenorator(particles[i], ver3f(particles[i].Position().add(ver3f(5.0, 0.0, 0.0))), 5.0) : AnchoredEqualityConstrainGenorator(particles[i], ver3f(particles[i].Position().add(ver3f(0.0, 5.0, 0.0))), 5.0);
                aecg.push_back(anchor);
            }
            break;
        case 2:
            for (int i = 0; i < 2;i++)
            {
                Particle p = Particle(-10+(i*20), 1.0, -5.0, 1);
                p.setVelocity((i==0) ? 5.0:-5.0, 0.0, 0.0);
                particles.push_back(p);
            }
            break;
        case 3:
            for (int i = 0; i < 5;i++)
            {
                Particle p = Particle(-10+(i*2), 10.0, 5.0, 1);
                particles.push_back(p);
            }
            break;
        default:
            break;
    }
}
/*
 *  Utility Methods
 */
void specialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT){
        rotX += 10;
    }else if(key == GLUT_KEY_RIGHT){
        rotX -= 10;
    } else if(key == GLUT_KEY_UP){
        rotY += 10;
    } else if(key == GLUT_KEY_DOWN){
        rotY -= 10;
    } else if(key == '+'){
        dist -= 5.0f;
    } else if(key == '-'){
        dist += 5.0f;
    } else if(key == 'l'){
        //panning right
        verX += 1.0;
    } else if(key == 'j'){
        //panning left
        verX -= 1.0;
    }else if(key == 'i'){
        //panning up
        verY += 1.0;
    }else if(key == 'k'){
        //panning down
        verY -= 1.0;
    }else if(key == '1'){
        mode = 1;
    }else if(key == '2'){
        mode = 2;
    }else if(key == GLUT_KEY_F1){
        multiView = false;
        demoMode = 0;
    }else if(key == GLUT_KEY_F2){
        multiView = true;
        demoMode = 0;
    } else if (key == GLUT_KEY_F3){
        multiView = false;
        demoMode = 1;
        reset();
    }else if (key == GLUT_KEY_F4){
        multiView = false;
        demoMode = 2;
        reset();
    }else if (key == GLUT_KEY_F5){
        multiView = false;
        demoMode = 3;
        reset();
    }else if (key == '9')
    {
        model = new AdvancedModel(3);
    }else if (key == '8')
    {
        model = new AdvancedModel(2);
    }else if (key == '7')
    {
        model = new AdvancedModel(1);
    }
    glutPostRedisplay();
}
