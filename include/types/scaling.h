/*Contains data structs that define scaled interactions - van der Waal's and qq*/
  //Shivw
  
typedef struct {
          int nr; //Number of molecules
          float **lookup; //lookup table
  	} t_scaling;
float lookup_table(float **table,int x,int y);
