//
//  lightSystem.cpp
//  AreaLightTesting
//
//  Created by wenziyang on 16/2/5.
//
//

#include "LightSystem.hpp"

void LightSystem::setup(){
       
    light.setup();
    light.enable();
   
    light.setPointLight();
    //light.setAreaLight(400,200);
    //light.setSpotlight(80,3);
    
    
    light.setAmbientColor(ofFloatColor(0.1,0.1,0.1));
    light.setAttenuation(1.0,0.0001,0.0001);
    light.setDiffuseColor(ofFloatColor(1,1,1));
    light.setSpecularColor(ofFloatColor(1,1,1));
    
    
    lightPos.set(0,0,0);
    //---   ÁÅØÂÖâÈªòËÆ§ÊòØÊúùÂêë y ËΩ¥ÁöÑË¥üÊñπÂêë
    light.setOrientation(ofPoint(-30,0,0));
    
    
    
    //---   ÂèÇÊï∞ 1Ôºå2 ËÆæÁΩÆÂπ≥Èù¢ÁöÑÈïøÂ∫¶ÔºåÂÆΩÂ∫¶   ÂèÇÊï∞ 3Ôºå4 ËÆæÁΩÆÂπ≥Èù¢ËæπÊï∞
    
    plane.set(1000,1000,8,5);
    
    materialPlane.setAmbientColor(ofFloatColor(0.1,0.1,0.1,1.0));
    materialPlane.setDiffuseColor(ofFloatColor(0.8,0.8,0.8,1.0));
    materialPlane.setSpecularColor(ofFloatColor(0.8,0.8,0.8,1.0));
    materialPlane.setShininess(1);
    
    
    
    gui.setup(); // most of the time you don't need a name
    //gui.add(value1.set("value",20,0,100));
    
    gui.add(lightDiffuseColor.set("lightDiffuseColor", ofFloatColor(1.0,1.0,1.0,0.5), ofFloatColor(0, 0,0,0), ofFloatColor(1,1,1,1)));
    
    gui.add(lightSpecularColor.set("lightSpecularColor", ofFloatColor(0.5,0.5,0.5,0.5), ofFloatColor(0, 0,0,0), ofFloatColor(1,1,1,1)));
    
    gui.add(planeDiffuseColor.set("planeDiffuseColor", ofFloatColor(0.5,0.5,0.5,0.5), ofFloatColor(0, 0,0,0), ofFloatColor(1,1,1,1)));
    
    gui.add(planeSpecularColor.set("planeSpecularColor", ofFloatColor(0.5,0.5,0.5,0.5), ofFloatColor(0, 0,0,0), ofFloatColor(1,1,1,1)));
    
    gui.add(planeShininess.set("planeShininess", 10,1,20));
    
    gui.add(lightAttenuation1.set("lightAttenuation1",1,0.1,5));
    
    gui.add(lightAttenuation2.set("lightAttenuation2",3,1,10));
    
    gui.add(lightAttenuation3.set("lightAttenuation3",3,1,10));
    
    if(light.getIsSpotlight()){
        gui.add(spotConcentration.set("spotConcentration",0.5,0.1,3));
    }
    
    lightPos.y = 300;
    camera.setOrientation(ofPoint(-17.5176, -0.507757, 0));
    showGui = true;
    showPlane = true;
    gui.loadFromFile("settings1.xml");
    
}

void LightSystem::update(){
    light.setPosition(lightPos);
    
    plane.setOrientation(ofPoint(-90,0,0));
    
    light.setDiffuseColor(lightDiffuseColor);
    light.setSpecularColor(lightSpecularColor);
    
    materialPlane.setDiffuseColor(planeDiffuseColor);
    materialPlane.setSpecularColor(planeSpecularColor);
    materialPlane.setShininess(0.00000001 * pow(10,planeShininess));
    
    
    float change1,change2,change3;
    change1 = (0.00000001 * pow(10,lightAttenuation1));
    change2 = (0.00000001 * pow(10,lightAttenuation2));
    change3 = (0.00000001 * pow(10,lightAttenuation3));
    
    light.setAttenuation(change1,change2,change3);
    
    //---   ÂΩìÁÅØÂÖâÊòØËÅöÂÖâÁÅØÊó∂ÔºåÂä†ÂÖ• concentra Â±ûÊÄß
    if(light.getIsSpotlight()){
        light.setSpotConcentration(spotConcentration);
    }
}

void LightSystem::begin(){
    camera.begin();
    ofEnableLighting();
    ofSetDepthTest(true);
}

void LightSystem::end(){
   
    
    ofDrawAxis(90);
    
    if(showPlane){
        materialPlane.begin();
        
        plane.draw();
        
        
        
//        ofPoint a,b,c;
//        a.set(-400,80,-200);
//        b.set(300,80,100);
//        c.set(-200,80,400);
//        
//        ofDrawTriangle(a, b, c);
        
        ofPoint a,b,c;
        ofMesh mesh;
        a.set(-400,80,-200);
        b.set(300,80,100);
        c.set(-200,80,400);
        mesh.addVertex(a);
        mesh.addVertex(b);
        mesh.addVertex(c);
        
        setNormals(mesh);
        mesh.draw();
        
       


        
        // plane.drawWireframe();
        
        materialPlane.end();
    }
    light.draw();
    camera.end();
    
    ofDisableLighting();
    ofSetDepthTest(false);
    if(showGui){
        gui.draw();
    }
}

void LightSystem::draw(){
    begin();
    end();
}
void LightSystem::setNormals( ofMesh &mesh ){
    //The number of the vertices
    int nV = mesh.getNumVertices();
    //The number of the triangles
    int nT = mesh.getNumIndices() / 3;
    vector<ofPoint> norm( nV ); //Array for the normals
    //Scan all the triangles. For each triangle add its
    //normal to norm's vectors of triangle's vertices
    for (int t=0; t<nT; t++) {
        //Get indices of the triangle t
        int i1 = mesh.getIndex( 3 * t );
        int i2 = mesh.getIndex( 3 * t + 1 );
        int i3 = mesh.getIndex( 3 * t + 2 );
        //Get vertices of the triangle
        const ofPoint &v1 = mesh.getVertex( i1 );
        const ofPoint &v2 = mesh.getVertex( i2 );
        const ofPoint &v3 = mesh.getVertex( i3 );
        //Compute the triangle's normal
        ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
        //Accumulate it to norm array for i1, i2, i3
        norm[ i1 ] += dir;
        norm[ i2 ] += dir;
        norm[ i3 ] += dir;
    }
    
    //Normalize the normal's length
    for (int i=0; i<nV; i++) {
        norm[i].normalize();
    }
    //Set the normals to mesh
    mesh.clearNormals();
    mesh.addNormals( norm );
}


void LightSystem::keyPressed(int key){
    if(key == '='){
        lightPos.y += 10;
    }
    if(key == '-'){
        lightPos.y -= 10;
    }
}