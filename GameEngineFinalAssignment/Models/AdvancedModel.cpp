//
//  AdvancedModel.cpp
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 21/12/2014.
//  Copyright (c) 2014 Yoshine LTD. All rights reserved.
//

#include "AdvancedModel.h"

AdvancedModel::AdvancedModel(int i)
{
    switch(i)
    {
        case 1:
            if(loadObj("/Users/seanobrien/Google Drive/Collage/Semester 1 4th Year/Game Engine Dev/GameEngineFinalAssignment/GameEngineFinalAssignment/Models/Sword.obj"))
            {
                cout<<"Success"<<endl;
            }
            break;
        case 2:
            if(loadObj("/Users/seanobrien/Google Drive/Collage/Semester 1 4th Year/Game Engine Dev/GameEngineFinalAssignment/GameEngineFinalAssignment/Models/ModelAdvanced.obj"))
            {
                cout<<"Success"<<endl;
            }
            break;
        case 3:
            if(loadObj("/Users/seanobrien/Google Drive/Collage/Semester 1 4th Year/Game Engine Dev/GameEngineFinalAssignment/GameEngineFinalAssignment/Models/Ducts.obj"))
            {
                cout<<"Success"<<endl;
            }
            break;
        default:
            break;
    }
}

void AdvancedModel::render(int mode)
{
    
    glColor3f(0,0,0);
    for (unsigned int i = 0; i < vertices.size(); i+=3)
    {
        glNormal3f ( normals[i].x, normals[i].y, normals[i].z );
        glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);
        glVertex3f(vertices[i+1].x,vertices[i+1].y,vertices[i+1].z);
        glVertex3f(vertices[i+2].x,vertices[i+2].y,vertices[i+2].z);
        if(mode == 2){
            glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);
        }
    }
    
}

bool AdvancedModel::loadObj(const char * path)
{
    vector<unsigned int> vertexInt,normalInt,UVInt;
    vector<Vertex> temp_Verts;
    vector<Normals> temp_Normals;
    vector<UVS> temp_UVS;
    
    FILE * file =fopen (path, "r");
    if (file == NULL){
        printf("File Could Not Be Open, Check Path!");
        return false;
    }else{
        while(true){
            char lineStart[128];
            int res = fscanf(file, "%s", lineStart);
            if (res == EOF){
                cout<<"EOF"<<endl;
                break;
            }else{
                if (strcmp(lineStart, "v")==0){
                    Vertex vert;
                    fscanf(file, "%f %f %f\n",&vert.x,&vert.y,&vert.z);
                    temp_Verts.push_back(vert);
                }else if(strcmp(lineStart, "vt")==0){
                    UVS uv;
                    fscanf(file, "%f %f\n",&uv.u,&uv.v);
                    temp_UVS.push_back(uv);
                }else if(strcmp(lineStart, "vn")==0){
                    Normals norm;
                    fscanf(file, "%f %f %f\n",&norm.x,&norm.y,&norm.z);
                    temp_Normals.push_back(norm);
                }else if(strcmp(lineStart, "f")==0){
                    unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                    int check = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                                                             &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                                                                             &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
                    if(check != 9){
                        return false;
                    }
                    vertexInt.push_back(vertexIndex[0]);
                    vertexInt.push_back(vertexIndex[1]);
                    vertexInt.push_back(vertexIndex[2]);
                    UVInt.push_back(uvIndex[0]);
                    UVInt.push_back(uvIndex[1]);
                    UVInt.push_back(uvIndex[2]);
                    normalInt.push_back(normalIndex[0]);
                    normalInt.push_back(normalIndex[1]);
                    normalInt.push_back(normalIndex[2]);
                }
            }
        }
        for(int i = 0 ; i< vertexInt.size();i++){
            Vertex vert = temp_Verts[vertexInt[i]-1];
            vertices.push_back(vert);
        }
        for(int i = 0 ; i< UVInt.size();i++){
            UVS uvsObj = temp_UVS[UVInt[i]-1];
            uvs.push_back(uvsObj);
        }
        for(int i = 0 ; i< normalInt.size();i++){
            Normals norm = temp_Normals[normalInt[i]-1];
            normals.push_back(norm);
        }
        return true;
    }
}