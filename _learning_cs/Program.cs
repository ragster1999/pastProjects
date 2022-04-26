/* HelloWorld.cs
First C# Program
@author Ramon Gonzalez
*/

using System; // basic utilities and promitive types
using System.Collections.Generic; // used for lists, collections
using System.Linq; // used for data
using System.Text; // used for text, encoding
using System.Threading.Tasks; // used to build multi-threaded applications



namespace HelloWorld
{
    
    class Program
    {
        static void Main(string[] args)
        {
           // Program00_HelloWorld();
           // Program01_Types();
           // Program02_PrimTypes();
           // Program03_NonPrimTypes();
           Program04_ControlFlow();
           
        }

        static void Program00_HelloWorld()
        {
            System.Console.WriteLine("Hello World!");
        }

        static void Program01_Types()
        {
             byte number = 5;
            int count = 10;
            float totalPrice = 20.3f;
            char character = 'A';
            string firstName = "Alex";
            bool isWorking = false;
            
            Console.WriteLine(number);
            Console.WriteLine(count);
            System.Console.WriteLine(totalPrice);
            System.Console.WriteLine(character);
            System.Console.WriteLine(firstName);
            System.Console.WriteLine(isWorking);

            System.Console.WriteLine("\nbyteMin:{0} byteMax:{1}", byte.MinValue, byte.MaxValue);
        }

        static void Program02_PrimTypes()
        {
            int i = 1;
            byte b = (byte) i; // typecast to byte since (big --> smol)
            System.Console.WriteLine(i);

            string number = "1234";
            int ii = Convert.ToInt32(number);

            System.Console.WriteLine(ii);

        }
        public class Calculator // Declare object
        {
            public int Add(int a, int b)
            {
                return a + b;
            }
        }
        
        static void Program03_NonPrimTypes()
        {
            // Classes
            Calculator calc = new Calculator(); // instantiate new calculator (can use var)
            Person guy = new Person();

            int result = calc.Add(1,2);
            var person = new Person();
            person.FirstName = "Alex";
            person.LastName = "Gonzalez";
            person.Introduce();

            // Arrays - a collection of variables of the same type
            int[] numbers = new int[3]; // array of size 3
            var names = new string[3] {"Ramon", "Alex", "Adrian"}; // init shortcut 

            // Enums - a set of name/value pairs (constants)
            var method = ShippingMethod.Express;
            var methodID = 3;
            System.Console.WriteLine((ShippingMethod)methodID);
            System.Console.WriteLine(method);
        }


        static void Program04_ControlFlow()
        {
            // Conditional statements

            // Exercises
            var ex = new Exercises04();

            // ex.Exercise04_01();
            // ex.Exercise04_02();
            // ex.Exercise04_04();
        }
    }
} 