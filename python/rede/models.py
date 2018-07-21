class Aluno(object):
    def __init__(self,nome,mat,turma,n):
        self.__nome = nome
        self.__mat = mat
        self.__turma = turma
        self.__n = n
    
    #Getters Methods
    def getNome(self):
        return self.__nome
    def getMat(self):
        return self.__mat
    def getTurma(self):
        return self.__turma
    def getN(self):
        return self.__n
    
    #Setters Methods
    def setNome(self,nome):
        self.__nome = nome
    def setMat(self,mat):
        self.__mat = mat
    def setTurma(self, turma):
        self.__turma = turma
    def setN(self,n):
        self.__n = n

    @staticmethod
    def auto_cadastro(arqName):
        arq = open(arqName,"r")

        lines = arq.readlines()

        alunos = list()

        for i in range(0,len(lines),2):
            nome = str(lines[i])
            dados = str(lines[i+1])
            dados = dados.split()
            mat = int(dados[0])
            turma = str(dados[1])
            n = [float(dados[2]),float(dados[3]),float(dados[4]),float(dados[5])]
            alunos.append(Aluno(nome,mat,turma,n))
        return alunos
