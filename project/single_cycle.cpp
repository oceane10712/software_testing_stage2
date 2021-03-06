#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<climits>
#include<queue>
#include"single_cycle.h"
#include<cstring>
/*
FILE * iimage;
FILE * dimage;
FILE * error_dump;
FILE * snapshot;
FILE * message;
*/

/*
void printItype(unsigned int x,int rs,int rt,int immediate,int lui){

    fprintf(message,"cycle %d:\n",cycle);
    fprintf(message,"%.8X\n",x);
    
    if(lui==1){
        fprintf(message,"rt %d immediate %d\n",rt,immediate);
        fprintf(message,"Reg[rt] %.8X",Reg[rt]);
    }else{
        fprintf(message,"rs %d rt %d immediate %d\n",rs,rt,immediate);
        fprintf(message,"Reg[%d] %.8X Reg[%d] %.8X\n",rs,Reg[rs],rt,Reg[rt]);
    }
    
    
}
*/

/*
void printRtype(unsigned int x,int rs,int rt,int rd,int shamt,int jr){
    
    fprintf(message,"cycle %d:\n",cycle);
    fprintf(message,"%.8X\n",x);
    if(jr==1){//instruction jr
        fprintf(message,"rs %d\nReg[rs] %.8X\n",rs,Reg[rs]);
    }else if(shamt==0){
        fprintf(message,"rs %d rt %d rd %d\n",rs,rt,rd);
        fprintf(message,"Reg[rs] %.8X Reg[rt] %.8X Reg[rd] %.8X\n",Reg[rs],Reg[rt],Reg[rd]);
        
    }else{
        fprintf(message,"rt %d rd %d shamt %d\n",rt,rd,shamt);
        fprintf(message,"Reg[%d] %.8X Reg[%d] %.8X\n",rt,Reg[rt],rd,Reg[rd]);
    }
    
    
}
*/
/*
void printJtype(unsigned int x,unsigned int PC){

    
    fprintf(message,"%.8X\n",x);
    fprintf(message,"PC %d\n",PC);
    unsigned int C  = x & 0x3FFFFFF;
    fprintf(message,"%.8X\n",(PC+4)>>28|4*C);

}
*/
/*
void printType(char str[]){

    //fprintf(message,"cycle %d",cycle);
    fprintf(message,"%s\n\n\n\n\n\n\n\n\n\n",str);
    

}
*/
/*
void printload(int address,int byteNum,int result){

    fprintf(message,"address %d\n",address);
    for(int i=0;i<byteNum;i++){
        fprintf(message,"Dmemory[%d] %.8X\n",address+i,Dmemory[address+i]);
    }
    fprintf(message,"Reg[rt] %.8X\n",result);
    

}
*/
/*
void printstore(int address,int byteNum){

    for(int i=0;i<byteNum;i++){
        fprintf(message,"Dmemory[%d] %.8X\n",address+i,Dmemory[address+i]);
    }

}
*/


















int Simulate::signExtension(int instr){
    int value = (0x0000FFFF & instr);
    int mask = 0x00008000;
    if(mask & instr){
        value+=0xFFFF0000;
    }
    return value;
}

unsigned int Simulate::endian_swap(unsigned int& x){
    x = (x>>24) | ((x<<8) & 0x00FF0000) | ((x>>8) & 0x0000FF00) | (x<<24);
    return x;
}

unsigned int Simulate::LoadMemory(int address,int byteNum,int sign){
    int temp=0,i;
    int MSB;
    
    MSB=Dmemory[address]>>7;
    
    for (i=0;i<=byteNum-1;i++)
    {
        temp=(temp<<8);
        temp=temp|Dmemory[address+i];
    }
    
    if (sign==1&&MSB==1&&byteNum!=4)
    {
        temp=temp|(0xffffffff<<(8*byteNum));
    }
    return temp;
}



void Simulate::Addi(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
//    printItype(x,rs,rt,immediate,-1);
    
    Write0Error(rt);
    numberOverflow(Reg[rs],immediate);
    
    if(donothingFlag!=1){
        Reg[rt]=Reg[rs]+immediate;
    }
    donothingFlag=0;
    
    PC=PC+4;
}
void Simulate::Lw(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    unsigned int address = Reg[rs]+immediate;//D Memory address
//    printItype(x,rs,rt,immediate,-1);
    
    Write0Error(rt);
    numberOverflow(Reg[rs],immediate);
    if(MemoryAddressOverflow( address , 4 )) flag=1;
    if(MisalignmentError( address , 4 )) flag=1;
    if(flag==1) {flag=0;return;}
    
    if(donothingFlag==0){
        Reg[rt]=(Dmemory[address]<<24|Dmemory[address+1]<<16|Dmemory[address+2]<<8|Dmemory[address+3]);
        
 //       printload(address,4,Reg[rt]);
    }
    
    
    donothingFlag=0;
    PC=PC+4;
    
    
}
void Simulate::Lh(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    unsigned int address = Reg[rs]+immediate;
    char word1,word2;
//    printItype(x,rs,rt,immediate,-1);
    
    Write0Error(rt);
    numberOverflow( Reg[rs],immediate );
    if(MemoryAddressOverflow( address , 2 )) flag=1;
    if(MisalignmentError( address , 2 )) flag=1;
    if(flag==1) {flag=0;return;}
    
    if(donothingFlag==0){
        word1=Dmemory[address];
        word2=Dmemory[address+1];
        int temp=0;
        int MSB;
        
        MSB=Dmemory[address]>>7;
        
        for (int i=0;i<=1;i++){
            temp=(temp<<8);
            temp=temp|Dmemory[address+i];
        }
        
        if (MSB==1) temp=temp|(0xffffffff<<(8*2));
        
        Reg[rt]=temp;
        
 //       printload(address,2,Reg[rt]);
    }
    donothingFlag=0;
    PC=PC+4;
    
}
void Simulate::Lhu(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    unsigned int address = Reg[rs]+immediate;
 //   printItype(x,rs,rt,immediate,-1);
    Write0Error(rt);
    numberOverflow(Reg[rs],immediate);
    if(MemoryAddressOverflow(address,2)) flag=1;
    if(MisalignmentError(address,2)) flag=1;
    if(flag==1) {flag=0;return;}
    
    if(donothingFlag==0){
        Reg[rt]=(Dmemory[address]<<8|Dmemory[address+1]);
//        printload(address,2,Reg[rt]);
    }
    
    donothingFlag=0;
    PC=PC+4;
    
    
}
void Simulate::Lb(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    unsigned int address = Reg[rs]+immediate;
 //   printItype(x,rs,rt,immediate,-1);
    Write0Error(rt);
    numberOverflow(Reg[rs],immediate);
    if(MemoryAddressOverflow(address,1)) flag=1;
    if(MisalignmentError(address,1)) flag=1;
    if(flag==1) {flag=0;return;}
    
    if(donothingFlag==0){
        Reg[rt]=signExtension((char)Dmemory[address]);
 //       printload(address,1,Reg[rt]);
    }
    donothingFlag=0;
    PC=PC+4;
    /*
     if(rt==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     PC=PC+4;
     }
     
     if(address>1023){
     fprintf(error_dump,"Memorr address overflow\n");
     haltflag=1;
     return;
     
     }else if(rt!=0){
     Reg[rt]=signExtension((char)Dmemory[address]);
     PC=PC+4;
     }
     */
}
void Simulate::Lbu(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    unsigned int address = Reg[rs]+immediate;
//    printItype(x,rs,rt,immediate,-1);
    Write0Error(rt);
    numberOverflow(Reg[rs],immediate);
    if(MemoryAddressOverflow(address,1)) flag=1;
    if(MisalignmentError(address,1)) flag=1;
    if(flag==1) {flag=0;return;}
    
    if(donothingFlag==0){
        Reg[rt]=Dmemory[address];
 //       printload(address,1,Reg[rt]);
    }
    donothingFlag=0;
    PC=PC+4;
    /*if(rt==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     PC=PC+4;
     }
     
     if(address>1023){
     fprintf(error_dump,"Memory address overflow\n");
     haltflag=1;
     return;
     
     }else if(rt!=0){
     Reg[rt]=Dmemory[address];
     PC=PC+4;
     }
     */
    
    
}
void Simulate::Sw(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    unsigned int address = Reg[rs]+immediate;
//    printItype(x,rs,rt,immediate,-1);
    numberOverflow(Reg[rs],immediate);
    if(MemoryAddressOverflow(address,4)) flag=1;
    if(MisalignmentError(address,4)) flag=1;
    if(flag==1) {flag=0;return;}
    
    
    /*
     if(address+3>1023){
     fprintf(error_dump,"Memory address overflow\n");
     haltflag=1;
     return;
     
     }
     if(address%4!=0){
     fprintf(error_dump,"In cycle %d: Misalignment Error\n",cycle);
     haltflag=1;
     return;
     }
     */
    
    
    
    if(donothingFlag==0){
        Dmemory[address]=(Reg[rt]&D0)>>24;
        Dmemory[address+1]=(Reg[rt]&D1)>>16;
        Dmemory[address+2]=(Reg[rt]&D2)>>8;
        Dmemory[address+3]=Reg[rt]&D3;
        
//        printstore(address,4);
    }
    donothingFlag=0;
    PC=PC+4;
    
    
    
    
}
void Simulate::Sh(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    unsigned int address= Reg[rs]+immediate;
//    printItype(x,rs,rt,immediate,-1);
    numberOverflow(Reg[rs],immediate);
    if(MemoryAddressOverflow(address,2)) flag=1;
    if(MisalignmentError(address,2)) flag=1;
    if(flag==1) {flag=0;return;}
    
    
    /*
     if(address+1>1023){
     fprintf(error_dump,"Memory address overflow\n");
     haltflag=1;
     return;
     
     }
     if(address%2!=0){
     fprintf(error_dump,"In cycle %d: Misalignment Error\n",cycle);
     haltflag=1;
     return;
     }
     */
    if(donothingFlag==0){
        Dmemory[address]=(Reg[rt] & 0x0000FF00)>>8;
        Dmemory[address+1]=(Reg[rt] & 0x000000FF);
        
 //       printstore(address,2);
    }
    donothingFlag=0;
    PC=PC+4;
    
    
}
void Simulate::Sb(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    unsigned int address = Reg[rs]+immediate;
//    printItype(x,rs,rt,immediate,-1);
    numberOverflow(Reg[rs],immediate);
    if(MemoryAddressOverflow(address,1)) flag=1;
    if(MisalignmentError(address,1)) flag=1;
    if(flag==1) {flag=0;return;}
    
    if(donothingFlag==0){
        Dmemory[address]=(Reg[rt] & 0x000000FF);
        
//        printstore(address,1);
    }
    donothingFlag=0;
    PC=PC+4;
    /*
     if(address>1023){
     fprintf(error_dump,"Memory address overflow\n");
     haltflag=1;
     return;
     
     }else{
     Dmemory[address]=(Reg[rt] & 0x000000FF);
     PC=PC+4;
     }
     */
    
}
void Simulate::Lui(unsigned int x,unsigned int rt,int immediate){
//    printItype(x,0,rt,immediate,1);
    Write0Error(rt);
    /*
     if(rt==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     //fprintf(snapshot,"rt %d immediate %d\n",rt,immediate);
     Reg[rt]=immediate<<16;
     }
     */
    if(donothingFlag==0) Reg[rt]=immediate<<16;
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Andi(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
//    printItype(x,rs,rt,immediate,0);
    Write0Error(rt);
    if(donothingFlag==0) Reg[rt]=Reg[rs] & (immediate&0x0000FFFF);
    /*
     if(rt==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     //fprintf(snapshot,"rt %d rs %d immediate %d\n",rt,rs,immediate);
     Reg[rt]=Reg[rs] & immediate;
     }*/
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Ori(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    unsigned short C=immediate&0x000000FFFF;
//    printItype(x,rs,rt,immediate,-1);
    Write0Error(rt);
    if(donothingFlag==0) Reg[rt]=Reg[rs]|C;
    /*
     if(rt==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     //fprintf(snapshot,"rt %d rs %d C %d\n",rt,rs,C);
     Reg[rt]=Reg[rs]|C;
     }
     */
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Nori(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
 //   printItype(x,rs,rt,immediate,-1);
    Write0Error(rt);
    if(donothingFlag==0) Reg[rt]=~(Reg[rs]|(immediate&0x0000FFFF));
    
    /*
     if(rt==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     //fprintf(snapshot,"rt %d rs %d immediate %d\n",rt,rs,immediate);
     Reg[rt]=~(Reg[rs]|(unsigned)immediate);
     }*/
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Slti(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
//    printItype(x,rs,rt,immediate,-1);
    Write0Error(rt);
    if(donothingFlag==0) Reg[rt]=(Reg[rs]<immediate);
    /*
     if(rt==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     //fprintf(snapshot,"rt %d rs %d immediate %d\n",rt,rs,immediate);
     Reg[rt]=(Reg[rs]<immediate);
     }*/
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Beq(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    //TODO not sure --> need check
    //fprintf(snapshot,"rt %d rs %d immediate %d\n",rt,rs,immediate);
    
    numberOverflow(PC,4+4*immediate);
    
    if(Reg[rs]==Reg[rt] && donothingFlag==0) PC=PC+4+4*immediate;
    else{
        donothingFlag=0;
        PC=PC+4;
    }
}
void Simulate::Bne(unsigned int x,unsigned int rs,unsigned int rt,int immediate){
    //TODO not sure --> need check
    //fprintf(snapshot,"rt %d rs %d immediate %d\n",rt,rs,immediate);
    numberOverflow(PC,4+4*immediate);
    
    if(Reg[rs]!=Reg[rt]&&donothingFlag==0) PC=PC+4+4*immediate;
    else{
        donothingFlag=0;
        PC=PC+4;
    }
}

//Rtype Instruction
void Simulate::Add(unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd){
//    printRtype(x,rs,rt,rd,0,-1);
    Write0Error(rd);
    numberOverflow(Reg[rs],Reg[rt]);
	if(donothingFlag==0) Reg[rd]=Reg[rs]+Reg[rt];
    
    /*
     if(rd==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }
     
     if(numberOverflow(Reg[rs],Reg[rt])==true){
     fprintf(error_dump,"In cycle %d: Number Overflow\n",cycle);
     
     }
     //fprintf(snapshot,"rs %d rt %d rd %d\n",rs,rt,rd);
     if(rd!=0){
     Reg[rd]=Reg[rs]+Reg[rt];
     }*/
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Sub(unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd){
//    printRtype(x,rs,rt,rd,0,-1);
    Write0Error(rd);
    numberOverflow(Reg[rs],-Reg[rt]);
    if(donothingFlag==0) Reg[rd]=Reg[rs]-Reg[rt];
    /*
     if(rd==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }
     
     if(numberOverflow(Reg[rs],-Reg[rt])==true){
     fprintf(error_dump,"In cycle %d: Number Overflow\n",cycle);
     
     }
     //fprintf(snapshot,"rs %d rt %d rd %d\n",rs,rt,rd);
     if(rd!=0){
     Reg[rd]=Reg[rs]-Reg[rt];
     }
     */
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::And(unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd){
//    printRtype(x,rs,rt,rd,0,-1);
    Write0Error(rd);
    if(donothingFlag==0) Reg[rd]=Reg[rs]&Reg[rt];
    /*
     if(rd==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     //fprintf(snapshot,"rs %d rt %d rd %d\n",rs,rt,rd);
     Reg[rd]=Reg[rs]&Reg[rt];
     }*/
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Or(unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd){
//    printRtype(x,rs,rt,rd,0,-1);
    Write0Error(rd);
    if(donothingFlag==0) Reg[rd]=Reg[rs]|Reg[rt];
    /*if(rd==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     // fprintf(snapshot,"rs %d rt %d rd %d\n",rs,rt,rd);
     Reg[rd]=Reg[rs]|Reg[rt];
     }*/
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Xor(unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd){
//    printRtype(x,rs,rt,rd,0,-1);
    Write0Error(rd);
    if(donothingFlag==0) Reg[rd]=Reg[rs]^Reg[rt];
    /*
     if(rd==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     // fprintf(snapshot,"rs %d rt %d rd %d\n",rs,rt,rd);
     Reg[rd]=Reg[rs]^Reg[rt];
     }*/
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Nor(unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd){
//    printRtype(x,rs,rt,rd,0,-1);
    Write0Error(rd);
    if(donothingFlag==0) Reg[rd]=~(Reg[rs]|Reg[rt]);
    
    /*
     if(rd==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     //fprintf(snapshot,"rs %d rt %d rd %d\n",rs,rt,rd);
     Reg[rd]=~(Reg[rs]|Reg[rt]);
     }
     */
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Nand(unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd){
//    printRtype(x,rs,rt,rd,0,-1);
    Write0Error(rd);
    if(donothingFlag==0) Reg[rd]=~(Reg[rs]&Reg[rt]);
    /*if(rd==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     //fprintf(snapshot,"rs %d rt %d rd %d\n",rs,rt,rd);
     Reg[rd]=~(Reg[rs]&Reg[rt]);
     }*/
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Slt(unsigned int x,unsigned int rs,unsigned int rt,unsigned int rd){
//    printRtype(x,rs,rt,rd,0,-1);
    Write0Error(rd);
    /*if(rd==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     //fprintf(snapshot,"rs %d rt %d rd %d\n",rs,rt,rd);
     Reg[rd]=(Reg[rs]<Reg[rt]);
     }*/
    if(donothingFlag==0) Reg[rd]=(Reg[rs]<Reg[rt]);
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Sll(unsigned int x,unsigned int rt,unsigned int rd,unsigned int shamt){
    //fprintf(snapshot,"rt %d rd %d shamt %d\n",rt,rd,shamt);
//    printRtype(x,0,rt,rd,shamt,-1);
    if(rd==0&&rt==0&&shamt==0){
        Reg[rd]=Reg[rt]<<shamt;
    }else if(rd==0){
        Write0Error(rd);
    }else{
        Reg[rd]=Reg[rt]<<shamt;
    }
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Srl(unsigned int x,unsigned int rt,unsigned int rd,unsigned int shamt){
//    printRtype(x,0,rt,rd,shamt,-1);
    Write0Error(rd);
    if(donothingFlag==0) Reg[rd]=((unsigned)Reg[rt])>>shamt;
    /*if(rd==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     // fprintf(snapshot,"rt %d rd %d shamt %d\n",rt,rd,shamt);
     Reg[rd]=((unsigned)Reg[rt])>>shamt;
     }*/
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Sra(unsigned int x,unsigned int rt,unsigned int rd,unsigned int shamt){
//    printRtype(x,0,rt,rd,shamt,-1);
    Write0Error(rd);
    if(donothingFlag==0) Reg[rd]=Reg[rt]>>shamt;
    /* if(rd==0){
     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
     }else{
     //fprintf(snapshot,"rt %d rd %d shamt %d\n",rt,rd,shamt);
     Reg[rd]=Reg[rt]>>shamt;
     }*/
    donothingFlag=0;
    PC=PC+4;
}
void Simulate::Jr(unsigned int x,unsigned int rs){
//    printRtype(x,rs,0,0,0,1);
    //fprintf(snapshot,"now PC %.8X\n",PC);
    //fprintf(snapshot,"rs %d Reg[rs] %.8X\n",rs,Reg[rs]);
    PC=Reg[rs];
}

void Simulate::J(unsigned int x){
    unsigned int C = x & 0x3FFFFFF;
    //fprintf(snapshot,"(PC+4)>>28|4*C %.8X\n",(PC+4)>>28|4*C);
//    printJtype(x,PC);
    
    PC = (PC+4)>>28|4*C;
    
}
void Simulate::Jal(unsigned int x){
    unsigned int C = x & 0x3FFFFFF;
    Reg[31] = PC+4;
    //fprintf(snapshot,"now PC 0x%.8X\n",PC);
    //fprintf(snapshot,"(PC+4)>>28|4*C %.8x\n",(PC+4)>>28|4*C);
//    printJtype(x,PC);
    PC = (PC+4)>>28|4*C;
}
void Simulate::halt(){
    //TODO  check
    //fprintf(snapshot,"halt\n");
    haltflag=1;
}

void Simulate::Rtype(unsigned int x){
    
    unsigned int funct = x & funcMask;
    unsigned int rs = (x & rsMask)>>21;
    unsigned int rt = (x & rtMask)>>16;
    unsigned int rd = (x & rdMask)>>11;
    unsigned int shamt = (x & shamtMask)>>6;
    char str[10];
    
    
    switch(funct){
        case 0x20:
            strcpy(str,"add");
            Add(x,rs,rt,rd);
            break;
        case 0x22:
            strcpy(str,"sub");
            Sub(x,rs,rt,rd);
            break;
        case 0x24:
            strcpy(str,"and");
            And(x,rs,rt,rd);
            break;
        case 0x25:
            strcpy(str,"or");
            Or(x,rs,rt,rd);
            break;
        case 0x26:
            strcpy(str,"xor");
            Xor(x,rs,rt,rd);
            break;
        case 0x27:
            strcpy(str,"nor");
            Nor(x,rs,rt,rd);
            break;
        case 0x28:
            strcpy(str,"nand");
            Nand(x,rs,rt,rd);
            break;
        case 0x2A:
            strcpy(str,"slt");
            Slt(x,rs,rt,rd);
            break;
        case 0x00:
            strcpy(str,"sll");
            Sll(x,rt,rd,shamt);
            break;
        case 0x02:
            strcpy(str,"srl");
            Srl(x,rt,rd,shamt);
            break;
        case 0x03:
            strcpy(str,"sra");
            Sra(x,rt,rd,shamt);
            break;
        case 0x08:
            strcpy(str,"jr");
            Jr(x,rs);
            break;
        default:
            strcpy(str,"Rtype default");
            break;
            
    }//end of switch
    
//    printType(str); 
    
    
    
}//end of Rtype


void Simulate::Itype(unsigned int x){
    unsigned int rs = (x & rsMask)>>21;
    unsigned int rt = (x & rtMask)>>16;
    unsigned int opcode = x>>26;
    short immediate = x & immediateMask;
    char str[20];
    switch(opcode){
        case 0x08:
            strcpy(str,"addi");
            Addi(x,rs,rt,immediate);
            break;
        case 0x23:
            strcpy(str,"lw");
            Lw(x,rs,rt,immediate);
            break;
        case 0x21:
            strcpy(str,"lh");
            Lh(x,rs,rt,immediate);
            break;
        case 0x25:
            strcpy(str,"lhu");
            Lhu(x,rs,rt,immediate);
            break;
        case 0x20:
            strcpy(str,"lb");
            Lb(x,rs,rt,immediate);
            break;
        case 0x24:
            strcpy(str,"lbu");
            Lbu(x,rs,rt,immediate);
            break;
        case 0x2B:
            strcpy(str,"sw");
            Sw(x,rs,rt,immediate);
            break;
        case 0x29:
            strcpy(str,"sh");
            Sh(x,rs,rt,immediate);
            break;
        case 0x28:
            strcpy(str,"sb");
            Sb(x,rs,rt,immediate);
            break;
        case 0x0F:
            strcpy(str,"lui");
            Lui(x,rt,immediate);
            break;
        case 0x0C:
            strcpy(str,"andi");
            Andi(x,rs,rt,immediate);
            break;
        case 0x0D:
            strcpy(str,"ori");
            Ori(x,rs,rt,immediate);
            break;
        case 0x0E:
            strcpy(str,"nori");
            Nori(x,rs,rt,immediate);
            break;
        case 0x0A:
            strcpy(str,"slti");
            Slti(x,rs,rt,immediate);
            break;
        case 0x04:
            strcpy(str,"beq");
            Beq(x,rs,rt,immediate);
            break;
        case 0x05:
            strcpy(str,"bne");
            Bne(x,rs,rt,immediate);
            break;
        default:
            strcpy(str,"Itype defalt");
            break;
            
            
    }//endof switch
    
    
    
//    printType(str); 
    
}//endof Itype

void Simulate::instruction(unsigned int x){
    unsigned	int opcode=x>>26;
    // fprintf(snapshot,"opcode %d\n",opcode);
    
    if(opcode==0){
		testType('R');
        Rtype(x);
    }else{
        switch(opcode){
            case 0x02:
                //fprintf(snapshot,"j\n");
				testType('J');
                J(x);
                break;
            case 0x03:
                //fprintf(snapshot,"jal\n");
				testType('J');
                Jal(x);
                break;
            case 0x3F:
                //fprintf(snapshot,"halt\n");
				testType('S');
                halt();
                break;
            default:
				testType('I');
                Itype(x);
                break;
        }
    }
    
    return;
}//end of instruction



void Simulate::Write0Error(int dest){
    
	char *error_zero;
	char buffer[50];

    if(dest==0){
   //     fprintf(error_dump,"In cycle %d: Write $0 Error\n",cycle);
	   	sprintf(buffer, "In cycle %d: Write $0 Error\n", cycle);
		error_zero = (char*)malloc(sizeof(buffer));
		strcpy(error_zero, buffer);
		errorList.push(error_zero);
	   	donothingFlag=1;
    }
   
}


void Simulate::numberOverflow(int a,int b){
    
	char *error_overflow;
	char buffer[50];

    if( a>0 && b>INT_MAX -a){
        //handle number overflow
       // fprintf(error_dump,"In cycle %d: Number Overflow\n",cycle);
        sprintf(buffer, "In cycle %d: Number Overflow\n", cycle);
		error_overflow = (char*)malloc(sizeof(buffer));
		strcpy(error_overflow, buffer);
		errorList.push(error_overflow);
      //  donothingFlag=1;
        
    }else if( a<0 && b<INT_MIN -a){
        //handle number overflow
//        fprintf(error_dump,"In cycle %d: Number Overflow\n",cycle);
      //  donothingFlag=1;
        sprintf(buffer, "In cycle %d: Number Overflow\n", cycle);
		error_overflow = (char*)malloc(sizeof(buffer));
		strcpy(error_overflow, buffer);
		errorList.push(error_overflow);
    }

}

bool Simulate::MemoryAddressOverflow(unsigned int address,int word){
//    fprintf(message,"address %d\n",address);
	 int add=address;
	 
	char *error_addressOverflow;
	char buffer[50];

	 if(add<0){
//		  fprintf(error_dump,"In cycle %d: Address Overflow\n",cycle);
        sprintf(buffer, "In cycle %d: Address Overflow\n", cycle);
		error_addressOverflow = (char*)malloc(sizeof(buffer));
		strcpy(error_addressOverflow, buffer);
		errorList.push(error_addressOverflow);
		  haltflag=1;
		  return true;

	 }else if(address+(word-1)>1023){
//        fprintf(error_dump,"In cycle %d: Address Overflow\n",cycle);
        sprintf(buffer, "In cycle %d: Address Overflow\n", cycle);
		error_addressOverflow = (char*)malloc(sizeof(buffer));
		strcpy(error_addressOverflow, buffer);
		errorList.push(error_addressOverflow);
        haltflag=1;
        return true;
    }else{
        return false;
    }
    
}
bool Simulate::MisalignmentError(int address,int word){
	 
	char *error_misalignment;
	char buffer[50];
    
    if(address % word !=0){
//        fprintf(error_dump,"In cycle %d: Misalignment Error\n",cycle);
        sprintf(buffer, "In cycle %d: Misalignment Error\n", cycle);
		error_misalignment = (char*)malloc(sizeof(buffer));
		strcpy(error_misalignment, buffer);
		errorList.push(error_misalignment);
        haltflag=1;
        return true;
    }else{
        return false;
    }
    
}
/*
void printReg(){
	FILE * snapshot;
    
    //	cout<<"in printReg"<<endl;
    
    snapshot=fopen("snapshot.rpt","a");
    
    fprintf(snapshot,"cycle %d\n",cycle);
    //	cout<<"test"<<endl;
    
    for(int i=0;i<32;i++){
        fprintf(snapshot,"$%02d: 0x%.8X\n",i,Reg[i]);
    }
    fprintf(snapshot,"PC: 0x%.8X\n\n\n",PC);
    
    fclose(snapshot);
}
*/


void Simulate::simulation(){
    
    
    //	cout<<endl<<"in simulation"<<endl;
    
    while(PC<1024){
        //	if(PC>1023) break;
        
		  if( (int)PC-(int)PCini < 0 ){
            //TODO need check
    //        fprintf(message,"(PC-PCini)<0\n");
            
	//			printReg();
				cycle++;
				PC=PC+4;
				continue;

        }
        

        if((PC-PCini)%4!=0){
            //TODO need check
     //       fprintf(message,"(PC-PCini)%%4 wrong\n");
            break;
        }
        if(PCini_invalid==1){
            break;
        }
        
        if(haltflag==1){
            //	printReg();
            break;
        }
        
    //    printReg();
        cycle++;
        
        //fprintf(message,"cycle %d:\n",cycle);
   //     fprintf(message,"PC    %.8X\nPCini %.8x\n",PC,PCini);
   //     fprintf(message,"instruction %.8X\n\n",Imemory[(PC-PCini)/4]);
        instruction(Imemory[(PC-PCini)/4]);
        
        
    }	
    
    
    
    
}

/*
void readFile(){
    //    cout<<endl<<"in readFile"<<endl;
    //fprintf(snapshot,"in readFile\n");
    int D=0,I=0;
    
    iimage = fopen ("iimage.bin","rb");
    if (iimage==NULL) {fputs ("File error",stderr); exit (1);}
    dimage = fopen ("dimage.bin","rb");
    if (dimage==NULL) {fputs ("File error",stderr);exit(1);}
    
    //initial value of PC
    fread(&PC,sizeof(unsigned int),1,iimage);
    PC = endian_swap(PC);
    if(PC<1024){ //if PCini overflow
        PCini = PC ;
    }else{
        PCini_invalid=1;
        fclose(iimage);
        fclose(dimage);
        return;
    }
    
    //number of words to be loaded into I memory
    fread(&i_num,sizeof(unsigned int),1,iimage);
    i_num = endian_swap(i_num);
    fprintf(message,"i_num %d\n",i_num);
    
    
    //I Memory
    while(fread(&buffer,sizeof(unsigned int),1,iimage)){
        buffer=endian_swap(buffer);
        //fprintf("%.8x \n",buffer);
        
        if(I>i_num-1)break;
        else if(I>255) break; //the address should be at most 1023 (1K size)
       
        Imemory[I++]=buffer;



    }
    
    //D Memory
    
    //initial value of $sp (reg $29)
    fread(&SP,sizeof(unsigned int),1,dimage);
  	 SP = endian_swap(SP);
    Reg[29]=SP;
    // fprintf(snapshot,"SP : %.8x\n",SP);
    
    fread(&d_num,sizeof(unsigned int),1,dimage);
    d_num = endian_swap(d_num);
    fprintf(message,"d_num %d\n",d_num);
    
    while (fread(&Dbuffer,sizeof(unsigned int),1,dimage)){
        Dbuffer = endian_swap(Dbuffer);
        //fprintf("%.8x \n",Dbuffer);
        //fprintf("%.8x \n",(Dbuffer&D0)>>24);
        //fprintf("%.8x \n",(Dbuffer&D1)>>16);
        //fprintf("%.8x \n",(Dbuffer&D2)>>8);
        //fprintf("%.8x \n",Dbuffer&D3);
        
        if(D>(d_num*4)-1) break;
        else if(D>1023) break;
		  Dmemory[D++]=(Dbuffer&D0)>>24;
        
		  if(D>(d_num*4)-1) break;
		  else if(D>1023) break;
		  Dmemory[D++]=(Dbuffer&D1)>>16;
        
		  if(D>(d_num*4)-1) break;
		  else if(D>1023) break;
		  Dmemory[D++]=(Dbuffer&D2)>>8;
        
		  if(D>(d_num*4)-1) break;
		  else if(D>1023) break;
		  Dmemory[D++]=Dbuffer&D3;
        
    }   
}
*/
void Simulate::initialize(){
		  
		  
		  haltflag=0;
          donothingFlag=0;
		  flag=0;
		  PCini_invalid=0;
		  memset(Reg,0,sizeof(Reg));
		  memset(Dmemory,0,sizeof(Dmemory));
		  memset(Imemory,0,sizeof(Imemory));

		  while(!errorList.empty()){
		  	errorList.pop();
printf("********\n");
		  }
}
/*
int main(){
   
   	snapshot=fopen("snapshot.rpt","w");
    error_dump=fopen("error_dump.rpt","w");
    message=fopen("message.rpt","w");
    
    
    initialize();
    readFile();
    simulation();
    
    fclose(snapshot);
    fclose(error_dump);
    fclose(message);
    return 0;
 
}
*/

void Simulate::setValue(unsigned int pc, unsigned int I_num, unsigned int I_buffer[], unsigned int sp, unsigned int D_num, unsigned int D_buffer[])
{
	initialize();

	PC = pc;
	i_num = I_num;
	
	if(PC < 1024){
		PCini = PC;
	}
	else{
        PCini_invalid=1;
	}

	for(int i=0; i<i_num; i++){
		Imemory[i] = I_buffer[i];
	}

	SP = sp;
	d_num = D_num;
    
	unsigned int D = 0;
	Reg[29]=SP;
 	for(int i=0; i<d_num; i++){
    	unsigned int Dbuffer = D_buffer[i];

	   	if(D>(d_num*4)-1) break;
        else if(D>1023) break;
		  Dmemory[D++]=(Dbuffer&D0)>>24;
        
		  if(D>(d_num*4)-1) break;
		  else if(D>1023) break;
		  Dmemory[D++]=(Dbuffer&D1)>>16;
        
		  if(D>(d_num*4)-1) break;
		  else if(D>1023) break;
		  Dmemory[D++]=(Dbuffer&D2)>>8;
        
		  if(D>(d_num*4)-1) break;
		  else if(D>1023) break;
		  Dmemory[D++]=Dbuffer&D3;
	}   
    
        
}

void Simulate::setReg(int id, int value)
{
	Reg[id] = value;
}

void Simulate::setDmemory(int d_num, unsigned int* D_buffer)
{
	unsigned int D = 0;
 	for(int i=0; i<d_num; i++){
    	unsigned int Dbuffer = D_buffer[i];

	   	if(D>(d_num*4)-1) break;
        else if(D>1023) break;
		  Dmemory[D++]=(Dbuffer&D0)>>24;
        
		  if(D>(d_num*4)-1) break;
		  else if(D>1023) break;
		  Dmemory[D++]=(Dbuffer&D1)>>16;
        
		  if(D>(d_num*4)-1) break;
		  else if(D>1023) break;
		  Dmemory[D++]=(Dbuffer&D2)>>8;
        
		  if(D>(d_num*4)-1) break;
		  else if(D>1023) break;
		  Dmemory[D++]=Dbuffer&D3;
	}   
}

int Simulate::getDmemoryByAddr(int address)
{
     return ((Dmemory[address] << 24) | (Dmemory[address+1] << 16) | (Dmemory[address+2] << 8) | Dmemory[address+3]);
}

void Simulate::setPC(int pc)
{
	 PC = pc;
}

void Simulate::testType(char t)
{
	char *type;
	char buffer[10];

	if(t == 'R'){
		sprintf(buffer, "Rtype\n", cycle);
	}
	else if(t == 'I'){
		sprintf(buffer, "Itype\n", cycle);
	}
	else if(t == 'J'){
		sprintf(buffer, "Jtype\n", cycle);
	}
	else if(t == 'S'){
		sprintf(buffer, "Stype\n", cycle);
	}
	type = (char*)malloc(sizeof(buffer));
	strcpy(type, buffer);
	snapshotList.push(type);
}
