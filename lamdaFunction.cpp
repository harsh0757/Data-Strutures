//SYNTAX
// [ captures ] ( parameters ) -> return_type {
//     // function body
// }

// Define a generic lambda that adds two numbers of any type
    // auto add = [](auto a, auto b) {
    //     return a + b;
    // };
//another method to declare
// auto add = [](int a, int b) -> int {
//         return a + b;
// };

#include <iostream>
using namespace std;

int main(){
    auto sub = [](int a, int b){
        return a-b;
    };

    int result = sub(5,4);
    cout<<result<<endl;
}