//Necessary includes
#define dDOUBLE
#include <ode/ode.h>
#include <drawstuff/drawstuff.h>
#include <stdio.h>

//First the objects for the simulation must be declared.
//You must have a world, 
//a space to put everything in, 
//a body with associated geometry and mass, 
//and a joint group to store the contact joints that are created during a collision.  
//(*joint = junta/encaixe = pontos de contato quando ocorre colisao)

// dynamics and collision objects
static dWorldID world;
static dSpaceID space;
static dBodyID body;	
static dGeomID geom;	
static dMass m;
static dJointGroupID contactgroup;	//vector of all contacts in simulation

//When the collision system detects that two objects are colliding, 
//it calls this routine which determines the points of contact and creates temporary joints. 
//The surface parameters of the joint (friction, bounce velocity, CFM, etc) are also set here. 

// this is called by dSpaceCollide when two objects in space are
// potentially colliding.
static void nearCallback (void *data, dGeomID o1, dGeomID o2)
{
    dBodyID b1 = dGeomGetBody(o1);
    dBodyID b2 = dGeomGetBody(o2);
    dContact contact;  
    contact.surface.mode = dContactBounce | dContactSoftCFM;
    // friction parameter
    contact.surface.mu = dInfinity;
    // bounce is the amount of "bouncyness".
    contact.surface.bounce = 0.9;
    // bounce_vel is the minimum incoming velocity to cause a bounce
    contact.surface.bounce_vel = 0.1;
    // constraint force mixing parameter
    contact.surface.soft_cfm = 0.001;  
    //dCollide = to get contact points for every single pair of geoms.
    //int dCollide (dGeomID o1, dGeomID o2, int flags, dContactGeom *contact, int skip);
    if (int numc = dCollide (o1,o2,1,&contact.geom,sizeof(dContact))) {
    	//dJointID dJointCreateContact (dWorldID, dJointGroupID, const dContact *);
        dJointID c = dJointCreateContact (world,contactgroup,&contact);
        //void dJointAttach (dJointID, dBodyID body1, dBodyID body2);
        dJointAttach (c,b1,b2);
    }
}

//This function is called at the start of the simulation to set up the point of view of the camera. 

// start simulation - set viewpoint
static void start()
{
    static float xyz[3] = {2.0f,-2.0f,1.7600f};
    static float hpr[3] = {140.000f,-17.0000f,0.0000f};
    dsSetViewpoint (xyz,hpr);
}

//This is the main simulation loop that calls the collision detection function, 
//steps the simulation, 
//resets the temporary contact joint group, 
//and redraws the objects at their new position. 

// simulation loop
static void simLoop (int pause)
{
    const dReal *pos;
    const dReal *R;
    // find collisions and add contact joints
    //void dSpaceCollide (dSpaceID space, void *data, dNearCallback *callback);
    dSpaceCollide (space,0,&nearCallback);
    // step the simulation
    //void dWorldQuickStep (dWorldID, dReal stepsize);
    dWorldQuickStep (world,0.01);  
    // remove all contact joints
    //void dJointGroupEmpty (dJointGroupID);
    dJointGroupEmpty (contactgroup);
    // redraw sphere at new location
    //const dReal * dGeomGetPosition (dGeomID);
    pos = dGeomGetPosition (geom);
    //const dReal * dGeomGetRotation (dGeomID);
    R = dGeomGetRotation (geom);
    //dReal dGeomSphereGetRadius (dGeomID sphere);
    dsDrawSphereD(pos,R,dGeomSphereGetRadius (geom));
}

//When the program starts, the callbacks are set up, everything is initialized, 
//and then the simulation is started. 

int main (int argc, char **argv)
{
    // setup pointers to drawstuff callback functions
    dsFunctions fn;
    fn.version = DS_VERSION;
    fn.start = &start;
    fn.step = &simLoop;
    fn.stop = 0;
    fn.command = 0;
    fn.path_to_textures = "/home/gabriel/ode-0.13.1/drawstuff/textures";
 
    dInitODE ();
    // create world
    world = dWorldCreate ();
    space = dHashSpaceCreate (0);
    dWorldSetGravity (world,0,0,-9.81);
    dWorldSetCFM (world,1e-5);
    dCreatePlane (space,0,0,1,0);
    contactgroup = dJointGroupCreate (0);
    // create object
    body = dBodyCreate (world);
    geom = dCreateSphere (space,0.5);
    dMassSetSphere (&m,1,0.5);
    dBodySetMass (body,&m);
    dGeomSetBody (geom,body);
    // set initial position
    dBodySetPosition (body,0,0,3);
    // run simulation
    dsSimulationLoop (argc,argv,352,288,&fn);
    // clean up
    dJointGroupDestroy (contactgroup);
    dSpaceDestroy (space);
    dWorldDestroy (world);
    dCloseODE();
    return 0;
}