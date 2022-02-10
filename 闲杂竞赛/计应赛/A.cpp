#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

class Computer{
private:
    string brand;
    int id;
    int total_score;
    int gpu_score;
    int cpu_score;
    int ram_score;
    int disk_score;
public:
    Computer(){};
    Computer(string brand,int id,int gpu_score,int cpu_score,int ram_score,int disk_score){
        this -> brand = brand;
        this -> id = id;
        this -> gpu_score = gpu_score;
        this -> cpu_score = cpu_score;
        this -> ram_score = ram_score;
        this -> disk_score = disk_score;
        this -> total_score = 5 * gpu_score + 4 * cpu_score + 3 * ram_score + 2 * disk_score;
    }
    string get_brand(){
        return this -> brand;
    }
    int get_id(){
        return this -> id;
    }
    int get_total_score(){
        return this -> total_score;
    }
    int get_gpu_score(){
        return this -> cpu_score;
    }
    int get_cpu_score(){
        return this -> cpu_score;
    }
    int get_ram_score(){
        return this -> ram_score;
    }
    int get_disk_score(){
        return this -> disk_score;
    }
};
bool cmp(Computer c1, Computer c2) 
{
    if (c1.get_total_score() == c2.get_total_score() ) {
        if (c1.get_gpu_score() == c2.get_gpu_score()) {
            if (c1.get_cpu_score() == c2.get_cpu_score()) {
                if (c1.get_ram_score() == c2.get_ram_score()){
                    return c1.get_disk_score() > c2.get_disk_score() ; 
                }
                return c1.get_ram_score() > c2.get_ram_score() ; 
            }
            return c1.get_cpu_score() > c2.get_cpu_score() ; 
        }
        return c1.get_gpu_score() > c2.get_gpu_score() ; 
    }
    return c1.get_total_score() > c2.get_total_score() ;
}
int main(){
    return 0;
}