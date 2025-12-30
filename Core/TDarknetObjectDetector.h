#ifndef RDK_TDarknetObjectDetectorH
#define RDK_TDarknetObjectDetectorH

//#include "TPythonIntegrationInclude.h"
//#include "TPythonIntegrationUtil.h"
#include "../../../Rdk/Deploy/Include/rdk.h"
#include "../ThirdParty/darknet/include/darknet_utils.h"

namespace RDK {

#define YOLOV2_INITTYPE 2
#define YOLOV3_INITTYPE 3

class TDarknetObjectDetector: public RDK::UNet
{
public: // 
///  
UProperty<UBitmap, TDarknetObjectDetector, ptPubInput> InputImage;
UProperty<UBitmap, TDarknetObjectDetector, ptPubOutput> OutputImage;

///  ,   ,    
/// ubmRGB24=3 -  
/// umbY8=400 - - 
UProperty<int,TDarknetObjectDetector, ptPubParameter> ImageColorModel;

///    (    )
UProperty<int,TDarknetObjectDetector, ptPubParameter> NumClasses;
///  ,      (probability)
UProperty<float,TDarknetObjectDetector, ptPubParameter> ProbabilityThreshold;
///  ,      (objectness)
UProperty<float,TDarknetObjectDetector, ptPubParameter> ObjectnessThreshold;
///    
UProperty<bool,TDarknetObjectDetector, ptPubParameter> FilterClassesList;
///
UProperty<std::vector<int>,TDarknetObjectDetector, ptPubParameter> ClassesList;

/// : 2 - YOLOV2
///                   3 - YOLOV3
//UProperty<int,TDarknetObjectDetector, ptPubParameter> InitializationTypeYOLO;

///    
UProperty<std::string,TDarknetObjectDetector, ptPubParameter> ConfigPath;
///    
UProperty<std::string,TDarknetObjectDetector, ptPubParameter> WeightsPath;



///   
//UProperty<std::string,TDarknetObjectDetector, ptPubParameter> ModelPathYOLO;
///     (    )
//UProperty<std::string,TDarknetObjectDetector, ptPubParameter> AnchorsPathYOLO;
///        
//UProperty<std::string,TDarknetObjectDetector, ptPubParameter> ClassesPathYOLO;

///     
//UProperty<bool,TDarknetObjectDetector, ptPubParameter> LoadTargetClassesYOLO;
///   (     ClassesPathYOLO   )
///!!!        ClassesPathYOLO
//UProperty<std::vector<std::string>,TDarknetObjectDetector, ptPubParameter> ChangeClassesYOLO;

///   
///UProperty<std::map<int, int>,TDarknetObjectDetector, ptPubParameter> ClassIndicesExchange;


///     
//UProperty<std::vector<int>,TDarknetObjectDetector, ptPubOutput> OutputClasses;

///  .     ,       
///  :
///    
///  4+2=Left; Top; Right; Bottom; Confidense, ClassNumber
UProperty<MDMatrix<double>, TDarknetObjectDetector> OutputObjects;

protected: //  

UGraphics Graph;
UBitmap Canvas;
bool Initialized;
std::string PythonScriptFileName;

int NumTargetClassesYOLO;
int NumChangeClassesYOLO;

std::vector<std::string> ClassedList;

network *Network;
layer TopLayer;

public: // 
// --------------------------
//   
// --------------------------
TDarknetObjectDetector(void);
virtual ~TDarknetObjectDetector(void);
// --------------------------

// ---------------------
//   
// ---------------------
// ---------------------

//bool SetPythonClassifierScriptPath(const std::string& path);
//const std::string &GetPythonClassifierScriptPath(void) const;

/*
bool SetNumTargetClassesYOLO(const int& num);
const int& GetNumTargetClassesYOLO(void) const;

bool SetNumChangeClassesYOLO(const int& num);
const int& GetNumChangeClassesYOLO(void) const;
*/
// ---------------------
//    
// ---------------------
// ---------------------

// --------------------------
//    
// --------------------------
//         
virtual TDarknetObjectDetector* New(void);
// --------------------------


// --------------------------
//    
// --------------------------
protected:
bool Initialize(void);
virtual void AInit(void);
virtual void AUnInit(void);

//        
virtual bool ADefault(void);

//     
//   
//    Reset()   Ready  true
//    
virtual bool ABuild(void);

//      
virtual bool AReset(void);

//    
virtual bool ACalculate(void);
// --------------------------

image UBitmapToImage(const UBitmap& ub);

};


}

#endif



