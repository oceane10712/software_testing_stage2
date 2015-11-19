#include<queue>

	const unsigned int funcMask=63;//00....00111111
	const unsigned int rsMask=65011712;
	const unsigned int rtMask=2031616;
	const unsigned int rdMask=63488;
	const unsigned int shamtMask=1984;
	const unsigned int immediateMask=0x0000FFFF;

	const unsigned int D0 = 4278190080;
	const unsigned int D1 = 16711680;
	const unsigned int D2 = 65280;
	const unsigned int D3 = 255;

class Simulate {

	private:
		
		unsigned int buffer,Dbuffer,i_num,SP,d_num;
		int haltflag,PCini_invalid,donothingFlag,flag;
	
	

	public:
	
		int cycle;
		int Reg[32];
		int PC,PCini;
		unsigned char Dmemory[1024];
		unsigned int Imemory[1024];
		std::queue<char*> snapshotList;
		std::queue<char*> errorList;

		Simulate(){ cycle = 0; }
		~Simulate(){}

		int signExtension(int instr);
		unsigned int endian_swap(unsigned int& x);
		//void printReg();
		void simulation();
		//void readFile();
		void initialize();
		void instruction(unsigned int x);
		unsigned int LoadMemory(int address,int byteNum,int sign);

		void Write0Error(int dest);
		void numberOverflow(int a,int b);
		bool MemoryAddressOverflow(unsigned int address,int word);
		bool MisalignmentError(int address,int word);
/*
void printItype(unsigned int x,int rs,int rt,int immediate,int lui);
void printRtype(unsigned int x,int rs,int rt,int rd,int shamt,int jr);
void printJtype(unsigned int x,unsigned int PC);
void printType(char str[]);
void printload(int address,int byteNum,int result);
void printstore(int address,int byteNum);
*/
		//Rtype
		void Rtype(unsigned int x);
		void Add (unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd);
		void Sub (unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd);
		void And (unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd);
		void Or  (unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd);
		void Xor (unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd);
		void Nor (unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd);
		void Nand(unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd);
		void Slt (unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd);
		void Sll (unsigned int x,unsigned int rt,unsigned int rd,unsigned int shamt);
		void Srl (unsigned int x,unsigned int rt,unsigned int rd,unsigned int shamt);
		void Sra (unsigned int x,unsigned int rt,unsigned int rd,unsigned int shamt);
		void Jr  (unsigned int x,unsigned int rs);
//Itype
		void Itype(unsigned int x);
		void Addi(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Lw(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Lh(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Lhu(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Lb(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Lbu(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Sw(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Sh(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Sb(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Lui(unsigned int x,unsigned int rt,int immediate);
		void Andi(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Ori(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Nori(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Slti(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Beq(unsigned int x,unsigned int rs,unsigned int rt,int immediate);
		void Bne(unsigned int x,unsigned int rs,unsigned int rt,int immediate);

		//Jtype
		void J(unsigned int x);
		void Jal(unsigned int x);
		//halt
		void halt();

		// init value
		void setValue(unsigned int pc, unsigned int I_num, unsigned int I_buffer[], unsigned int sp, unsigned int D_num, unsigned int D_buffer[]);
		void setReg(int id, int value);
		void setDmemory(int d_num, unsigned int* Dmemory);
	 	int getDmemoryByAddr(int address);
	 	void setPC(int pc);
		void testType(char t);
};

