'qualquer'

'interessante'

'util'

alignas (since C++11)
  // every object of type sse_t will be aligned to 16-byte boundary
  struct alignas(16) sse_t

alignof (since C++11)
  Alignment
  Every object type has the property called alignment requirement, which is an integer value (of type std::size_t, always a power of 2) 
  representing the number of bytes between successive addresses at which objects of this type can be allocated.
  
and_eq
  alternative operators: as an alternative for &=
  
  std::bitset<4> mask("1100");
  std::bitset<4> val("0111");
  val and_eq mask;
  
asm
  asm-declaration gives the ability to embed assembly language source code within a C++ program.
  
  // standard inline assembly
  asm ("movq $60, %rax\n\t" // the exit syscall number on Linux
       "movq $2,  %rdi\n\t" // this program returns 2
       "syscall");
  
auto(1)
  Specifies that the type of the variable that is being declared will be automatically deduced from its initializer. For functions, specifies 
  that the return type is a trailing return type or will be deduced from its return statements.
  
  template<class T, class U>
  auto add(T t, U u) -> decltype(t + u) // the return type is the type of operator+(T, U)
  {
    return t + u;
  }

bitand
  alternative operators: as an alternative for &
  
bitor
  alternative operators: as an alternative for |

catch
  try { /* */ } catch(const std::exception& e) { /* */ }

compl
  alternative operators: as an alternative for ~
  complex number
  template< class T >
  class complex;		  	(1) 	
  template<> class complex<float>;	(2) 	
  template<> class complex<double>;	(3) 	
  template<> class complex<long double>;(4) 
  
  using namespace std::literals;
  std::cout << std::fixed << std::setprecision(1);
 
  std::complex<double> z1 = 1i * 1i;     // imaginary unit squared
  std::cout << "i * i = " << z1 << '\n';

concept (concepts TS)
  Concept is a term that describes a named set of requirements for a type. 
  


const
constexpr (since C++11)
const_cast
continue
decltype (since C++11)
default(1)
delete(1)
do
double
dynamic_cast
else
enum
explicit
export(1)
extern
false
float
for
friend
goto
if
inline
int
long
mutable
namespace
new
noexcept (since C++11)
not
not_eq
nullptr (since C++11)
operator
or
or_eq
private
protected
public
register
reinterpret_cast
requires (concepts TS)
return
short
signed
sizeof
static
static_assert (since C++11)
static_cast
struct
switch
template
this
thread_local (since C++11)
throw
true
try
typedef
typeid
typename
union
unsigned
using(1)
virtual
void
volatile
wchar_t
while
xor
xor_eq 