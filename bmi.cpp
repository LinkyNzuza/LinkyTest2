// KJN - it is good practice to insert comment about intended use, context, contributors, etc
//Linky Nzuza contributor to this code
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ounces2pounds(int x)// function to convert ounces to pounds
{
    return(x*16);
}

int stones2pounds(int x)// function to convert stones to pounds
{
    return(x*14);
}

double weight2kg(int stones, int pounds, int ounces)// function to convert pounds to kilograms
{
    return (stones2pounds(stones)+pounds+ounces2pounds(ounces))/2.2;
}

double height2metres(int feet, int inches)// function to convert feet and inches to metres
{
    return(feet/3.28 + inches/39.37);
}

char categorise(double kg, double metre)// Function to calculate bmi and categorise the bmi results into categories
{
    double bmi = kg/metre*metre;
    char cat;
    if (bmi<19)
        cat='A';
    else if (bmi<25)
        cat='B';
    else if (bmi<30)
        cat='C';
    else
        cat='D';
    return(cat);
}

void process_data(char* input_file, char* output_file)// Function to read in data from a data file 
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string person_id;
    int pounds, stones, ounces, feet, inches;
    double kg, m;//Measurements of the converted units 
    char cat;

    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out);
    while (!f_in.eof())
    {
    	f_in >> person_id >> pounds >> stones >> ounces >> feet >> inches;// order of how measurements are read in
        kg=weight2kg(int(stones),int(pounds),int(ounces));
        m =height2metres(int(feet),int(inches));
        cat=categorise(kg,m);
	f_out << person_id << " " << cat << endl;
    }
    f_in.close();
    f_out.close();
}
        
int main(int argc, char *argv[])
{
    // KJN - Need to check that 3 arguments were supplied upon execution
    process_data(argv[1], argv[2]);
}
