#include <stdio.h>



#define _1_CONV_ROWS 6  

#define _1_CONV_COLS 1   

#define _1_CONV_NUMBER_ARRAY 4  



#define _2_CONV_ROWS 5   

#define _2_CONV_COLS 4   

#define _2_CONV_NUMBER_ARRAY 4  



#define _3_CONV_ROWS 4   

#define _3_CONV_COLS 4   

#define _3_CONV_NUMBER_ARRAY 10



#define _4_CONV_ROWS 4   

#define _4_CONV_COLS 10   

#define _4_CONV_NUMBER_ARRAY 10  



#define _5_CONV_ROWS 4   

#define _5_CONV_COLS 10   

#define _5_CONV_NUMBER_ARRAY 15 



#define _6_CONV_ROWS 6  

#define _6_CONV_COLS 15   

#define _6_CONV_NUMBER_ARRAY 8



#define _1_FC_ROWS 50  

#define _1_FC_COLS 8



#define _2_FC_ROWS 20  

#define _2_FC_COLS 50



#define _3_FC_ROWS 3  

#define _3_FC_COLS 20





double _1_CONV_weight[_1_CONV_NUMBER_ARRAY][_1_CONV_ROWS][_1_CONV_COLS];

double _2_CONV_weight[_2_CONV_NUMBER_ARRAY][_2_CONV_ROWS][_2_CONV_COLS];

double _3_CONV_weight[_3_CONV_NUMBER_ARRAY][_3_CONV_ROWS][_3_CONV_COLS];

double _4_CONV_weight[_4_CONV_NUMBER_ARRAY][_4_CONV_ROWS][_4_CONV_COLS];

double _5_CONV_weight[_5_CONV_NUMBER_ARRAY][_5_CONV_ROWS][_5_CONV_COLS];

double _6_CONV_weight[_6_CONV_NUMBER_ARRAY][_6_CONV_ROWS][_6_CONV_COLS];



double _1_CONV_bias[1][_1_CONV_NUMBER_ARRAY];

double _2_CONV_bias[1][_2_CONV_NUMBER_ARRAY];

double _3_CONV_bias[1][_3_CONV_NUMBER_ARRAY];

double _4_CONV_bias[1][_4_CONV_NUMBER_ARRAY];

double _5_CONV_bias[1][_5_CONV_NUMBER_ARRAY];

double _6_CONV_bias[1][_6_CONV_NUMBER_ARRAY];



double _1_FC_weight[_1_FC_ROWS][_1_FC_COLS];

double _2_FC_weight[_2_FC_ROWS][_2_FC_COLS];

double _3_FC_weight[_3_FC_ROWS][_3_FC_COLS];



double _1_FC_bias[_1_FC_ROWS][1];

double _2_FC_bias[_2_FC_ROWS][1];

double _3_FC_bias[_3_FC_ROWS][1];

double _input[1][4097][1];



void read_tensor(int const rows, int const cols, int const numberArray, const char* filename, double array[numberArray][rows][cols]){
    FILE *file;
    int i, j, k;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Can't open file\n");
        //return 1;
    }
    for (i = 0; i < numberArray; i++) {
        for (j = 0; j < rows; j++) {
            for (k = 0; k < cols; k++) {
            fscanf(file, "%lf", &array[i][j][k]);
            }
        }
    }
    fclose(file);
}



void read_array(int const R_, int const C_, const char* filename, double array[R_][C_]){
    FILE *file;
    int i, j;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Can't open file%s\n",filename);
        //return 1;
    }
    for (i = 0; i < R_; i++) {
        for (j = 0; j < C_; j++) {
            fscanf(file, "%lf", &array[i][j]);
        }
    }
    fclose(file);
}



int main() {

    int i, j, k;
/*
    //read parameters

    read_tensor(_1_CONV_ROWS,_1_CONV_COLS,_1_CONV_NUMBER_ARRAY,"CONV1C_6_1_4.txt",&_1_CONV_weight);   //read CONV1 weight

    read_array(1, _1_CONV_NUMBER_ARRAY,"CONV1B_1_4.txt",&_1_CONV_bias); //read CONV1 bias

    

    read_tensor(_2_CONV_ROWS,_2_CONV_COLS,_2_CONV_NUMBER_ARRAY,"CONV2C_5_4_4.txt",&_2_CONV_weight);   //read CONV2 weight

    read_array(1, _2_CONV_NUMBER_ARRAY,"CONV2B_1_4.txt",&_2_CONV_bias); //read CONV2 bias

    

    read_tensor(_3_CONV_ROWS,_3_CONV_COLS,_3_CONV_NUMBER_ARRAY,"CONV3C_4_4_10.txt",&_3_CONV_weight);   //read CONV3 weight

    read_array(1, _3_CONV_NUMBER_ARRAY,"CONV3B_1_10.txt",&_3_CONV_bias); //read CONV3 bias

    

    read_tensor(_4_CONV_ROWS,_4_CONV_COLS,_4_CONV_NUMBER_ARRAY,"CONV4C_4_10_10.txt",&_4_CONV_weight);   //read CONV4 weight

    read_array(1, _4_CONV_NUMBER_ARRAY,"CONV4B_1_10.txt",&_4_CONV_bias); //read CONV4 bias

    

    read_tensor(_5_CONV_ROWS,_5_CONV_COLS,_5_CONV_NUMBER_ARRAY,"CONV5C_4_10_15.txt",&_5_CONV_weight);   //read CONV5 weight

    read_array(1, _5_CONV_NUMBER_ARRAY,"CONV5B_1_15.txt",&_5_CONV_bias); //read CONV5 bias

    

   read_tensor(_6_CONV_ROWS,_6_CONV_COLS,_6_CONV_NUMBER_ARRAY,"CONV6C_6_15_8.txt",&_6_CONV_weight);   //read CONV6 weight

    read_array(1, _6_CONV_NUMBER_ARRAY,"CONV6B_1_8.txt",&_6_CONV_bias); //read CONV6 bias

    

    

    read_array(_1_FC_ROWS, _1_FC_COLS,"FC1C_50_8.txt",&_1_FC_weight); //read FC1 weight

    read_array(_1_FC_ROWS, 1,"FC1B_50_1.txt",&_1_FC_bias); //read FC1 bias

    

    read_array(_2_FC_ROWS, _2_FC_COLS,"FC2C_20_50.txt",&_2_FC_weight); //read FC2 weight

    read_array(_2_FC_ROWS, 1,"FC2B_20_1.txt",&_2_FC_bias); //read FC2 bias

    

    read_array(_3_FC_ROWS, _3_FC_COLS,"FC3C_3_20.txt",&_3_FC_weight); //read FC3 weight

    read_array(_3_FC_ROWS, 1,"FC3B_3_1.txt",&_3_FC_bias); //read FC3 bias

*/
    read_tensor(4097,1,1,"datafolder/O001.txt",&_input);

//    printf("read array：\n");

/*    for (i = 0; i < _2_FC_ROWS; i++) {
        for (j = 0; j < _2_FC_COLS; j++) {
            printf("%lf ", _2_FC_weight[i][j]);
        }
        printf("\n");
    }
*/



    for (i = 0; i < 1; i++) {   //////change {1 4097 1} to corresponding  {numberArray ROWS COLS}  
        for (j = 0; j < 4097; j++) {
            for (k = 0; k < 1; k++) {
            printf("%lf ", _input[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;

}



