#include <iostream>
#include <sstream>
#include <limits>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void append_to_dynamic_array(int*&,int,int&,int&);
void remove_dynamic_array_head(int* &,int &, int &);

inline void clear_stdin(){
  //std::cin.clear();
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

int main() {

  int as{};
  int ls{};
  std::cout << "Введите фактичеcкий размер массива: ";
  std::cin >> as;
  //do{
     std::cout << "Введите логичеcкий размер массива: ";
     std::cin >> ls;
     if(ls>as){
        std::cout<<"Ошибка! Логический размер массива не может превышать фактический!\n";
       return 1;
     }
  //}while(ls>as);
  int* arr = new int[as]();
  for(int i{};i<ls;i++){
    std::cout<<"Введите arr["<<i<<"]: ";
    std::cin>>arr[i];
  }
  clear_stdin();
  std::cout<<"Динамический массив: ";
  print_dynamic_array(arr,ls,as);
  std::string line;
  while(1){
    std::cout<<"Удалить первый элемент? ";
    std::cin>>line;
    if(line=="да"){
      if(ls){
        remove_dynamic_array_head(arr,as,ls);
      }else{
        std::cout<<"Невозможно удалить первый элемент, так как массив пустой. До свидания!";
        delete [] arr;
        return 2;
      }
    }else if(line=="нет"){
      break;
    }else{
      std::cout<<"Введите да или нет\n";
    }
    std::cout<<"Динамический массив: ";
    print_dynamic_array(arr,ls,as);
  }
  //clear_stdin();
  std::cout<<"\nСпасибо! Ваш динамический массив: ";
  print_dynamic_array(arr,ls,as);
  delete [] arr;

}

void print_dynamic_array(int* arr, int logical_size, int actual_size){
  //std::cout<<"Динамический массив: ";
  for(int i{};i<actual_size;i++){
    if(i<logical_size){
      std::cout<<arr[i];
    }else{
      std::cout<<"_";
    }
    if(i<actual_size-1){
      std::cout<<" ";
    }
  }
  std::cout<<"\n";
}

void append_to_dynamic_array(int* &arr,int new_num,int &as, int &ls){
   if(ls==as){
     as *= 2;
     int* new_arr = new int[as]();
     int* old_arr = arr;
     for(int i{};i<ls;i++){
        new_arr[i]=arr[i];
     }
     arr = new_arr;
     delete [] old_arr;
     //ls += 1;
   }
   arr[ls++] = new_num;
}

void remove_dynamic_array_head(int* &arr,int &as, int &ls){
   if(ls-1<=as/3){
     as /= 3;
     int* new_arr = new int[as]();
     int* old_arr = arr;
     for(int i{};i<ls-1;i++){
        new_arr[i]=arr[i+1];
     }
     arr = new_arr;
     delete [] old_arr;
     ls -= 1;
   }else{
     for(int i{};i<ls-1;i++){
         arr[i]=arr[i+1];
     }
     arr[(ls--)-1] = 0;
   }
}
