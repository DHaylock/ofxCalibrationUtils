#include "ofMain.h"
#include "ofxOpenCv.h"

class coordWarping{
    
public:

    //---------------------------
    coordWarping();
    
    //first calculate the matrix
    //do this only when it changes - saves cpu!
    void calculateMatrix(ofPoint src[4], ofPoint dst[4]);
    
    //returns true if the point is inside the src quad
    bool bInQuad(ofPoint pt);
    
    //then when ever you need to warp the coords call this
    ofPoint transform(float xIn, float yIn);
    
protected:
    
    ofPoint srcQuad[4];
    ofPoint dstQuad[4];
    
    CvPoint2D32f cvsrc[4];
    CvPoint2D32f cvdst[4];
    CvMat *translate;
    
};