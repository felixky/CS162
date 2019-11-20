#include "./f.h"

using namespace std;

void create_header(ifstream & ifile, ofstream & ofile){
   char temp[256];
   ofile << "<html>" << endl;
   ofile << "<head>" << endl;
   ofile << "<title>";
   ifile.getline(temp, 256);
   ofile << temp << "</title>"<< endl;
   ofile << "</head>" << endl;
  
}

void create_body(ifstream & ifile, ofstream & ofile){
   char temp[256], temp2[256], temp3[256], temp4[256], temp5[256], temp6[256];

   ifile >> temp;
   ofile << "<body bgcolor=\"" << temp << "\">" << endl;
   ifile >>temp2;
   ifile >>temp3;
   ifile.getline(temp4, 256);
   ofile << "<font color=\"" << temp2 << "\" size=\"" << temp3 << "\" face=\"" << temp4 << "\">" << endl;
   ifile.getline(temp5, 256);   
   ofile << temp5 << endl;
   ofile << "<br>" << endl;
   ifile.getline(temp6, 256);
   ofile << temp6;
   ofile << "<br>" << endl;
   ofile << "<br>" << endl;
   ofile << "</font>" << endl;
   ofile << "</body>" << endl;  
}

void create_html(ifstream & ifile){
   ofstream ofile;
   ofile.open("../../../public_html/index.html");

   create_header(ifile, ofile);
   create_body(ifile, ofile);
   ofile << "</html>" << endl;
   ifile.close();
   ofile.close();
}







