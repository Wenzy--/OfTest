//
//  lightSystem.hpp
//  AreaLightTesting
//
//  Created by wenziyang on 16/2/5.
//
//

#ifndef lightSystem_hpp
#define lightSystem_hpp

#include "ofMain.h"
#include "ofxGui.h"

class LightSystem{
public:
    ofLight light;
    ofPoint lightPos;
    ofPlanePrimitive plane;
    ofEasyCam camera;
    ofMaterial materialPlane;
    
    ofxPanel gui;
    bool showGui;
    bool showPlane;
    
    ofParameter<ofFloatColor> lightDiffuseColor;
    ofParameter<ofFloatColor> lightSpecularColor;
    
    ofParameter<ofFloatColor> planeDiffuseColor;
    ofParameter<ofFloatColor> planeSpecularColor;
    ofParameter<float> lightAttenuation1;
    ofParameter<float> lightAttenuation2;
    ofParameter<float> lightAttenuation3;
    ofParameter<float> planeShininess;
    
    ofParameter<float> spotConcentration;
    
    void setup();
    void update();
    void begin();
    void end();
    void draw();
    void keyPressed(int key);
    
    void setNormals( ofMesh &mesh );

};


#endif /* lightSystem_hpp */
