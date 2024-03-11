from experta import *

class Solve(KnowledgeEngine):
    def __init__(self):
        super().__init__()
        self.MDAndroidStudio = 0
        self.MDIntelliJIDEA = 0
        self.MDPyCharm = 0
        self.MDPhpStorm = 0
        self.MDJuNote = 0
        self.MDRStudio = 0
        self.MDXcode = 0
        self.MDVSCode = 0

        self.MNDAndroidStudio = 0
        self.MNDIntelliJIDEA = 0
        self.MNDPyCharm = 0
        self.MNDPhpStorm = 0
        self.MNDJuNote = 0
        self.MNDRStudio = 0
        self.MNDXcode = 0
        self.MNDVSCode = 0
        
    @Rule(
        Fact(answ="0-1"))
    def x1(self):
        self.MDIntelliJIDEA = self.MDIntelliJIDEA + 0.9 * (1-self.MDIntelliJIDEA)
        self.MDPyCharm = self.MDPyCharm + 0.9 * (1-self.MDPyCharm)
        self.MDPhpStorm = self.MDPhpStorm + 0.9 * (1-self.MDPhpStorm)
        self.MDVSCode = self.MDVSCode + 0.2 * (1-self.MDVSCode)
        
        self.MNDPhpStorm = self.MNDPhpStorm + 0.8 * (1-self.MNDPhpStorm)
        self.MNDJuNote = self.MNDJuNote + 0.8 * (1-self.MNDJuNote)
        self.MNDRStudio = self.MNDRStudio + 0.8 * (1-self.MNDRStudio)
        self.MNDPyCharm = self.MNDPyCharm + 0.8 * (1-self.MNDPyCharm)
        self.MNDVSCode = self.MNDVSCode + 0.4 * (1-self.MNDVSCode)
    
    
    @Rule(
        Fact(answ="0-3"))
    def x2(self):
        self.MDAndroidStudio = self.MDAndroidStudio + 0.9 * (1-self.MDAndroidStudio)
        self.MDXcode = self.MDXcode + 0.9 * (1-self.MDXcode)
        
        self.MNDJuNote = self.MNDJuNote + 0.8 * (1-self.MNDJuNote)
        self.MNDRStudio = self.MNDRStudio + 0.8 * (1-self.MNDRStudio)
        self.MNDVSCode = self.MNDVSCode + 0.6 * (1-self.MNDVSCode)
        self.MNDAndroidStudio = self.MNDAndroidStudio + 0.7 * (1-self.MNDAndroidStudio)
    
    
    @Rule(
        Fact(answ="1-1"))
    def s1(self):
        self.MDIntelliJIDEA = self.MDIntelliJIDEA + 0.9 * (1-self.MDIntelliJIDEA)
        self.MDAndroidStudio = self.MDAndroidStudio + 0.6 * (1-self.MDAndroidStudio)
        self.MDVSCode = self.MDVSCode + 0.1 * (1-self.MDVSCode)
        
        self.MNDPhpStorm = self.MNDPhpStorm + 0.8 * (1-self.MNDPhpStorm)
        self.MNDJuNote = self.MNDJuNote + 0.8 * (1-self.MNDJuNote)
        self.MNDRStudio = self.MNDRStudio + 0.8 * (1-self.MNDRStudio)
        self.MNDPyCharm = self.MNDPyCharm + 0.8 * (1-self.MNDPyCharm)
        
        
        
    @Rule(
        Fact(answ="1-2") | Fact(answ="0-2"))
    def s2(self):
        self.MDPyCharm = self.MDPyCharm + 0.9* (1-self.MDPyCharm)
        self.MDJuNote = self.MDJuNote + 0.9 * (1-self.MNDJuNote)
        self.MDVSCode = self.MDVSCode + 0.1 * (1-self.MDVSCode)
        
        self.MNDPhpStorm = self.MNDPhpStorm + 0.8 * (1-self.MNDPhpStorm)
        self.MNDIntelliJIDEA = self.MNDIntelliJIDEA + 0.8 * (1-self.MNDIntelliJIDEA)
        self.MNDAndroidStudio = self.MNDAndroidStudio + 0.8 * (1-self.MNDAndroidStudio)
        
        
    @Rule(
        Fact(answ="1-3"))
    def s3(self):
        self.MDPhpStorm = self.MDPhpStorm + 0.9 * (1-self.MDPhpStorm)
        self.MDVSCode = self.MDVSCode + 0.1 * (1-self.MDVSCode)
        
        self.MNDPyCharm = self.MNDPyCharm + 0.8 * (1-self.MNDPyCharm)
        self.MNDJuNote = self.MNDJuNote + 0.8 * (1-self.MNDJuNote)
        self.MNDRStudio = self.MNDRStudio + 0.8 * (1-self.MNDRStudio)
        self.MNDIntelliJIDEA = self.MNDIntelliJIDEA + 0.8 * (1-self.MNDIntelliJIDEA)
        self.MNDAndroidStudio = self.MNDAndroidStudio + 0.8 * (1-self.MNDAndroidStudio)
        
        
    @Rule(
        Fact(answ="1-4") | Fact(answ="0-3"))
    def s4(self):
        self.MDRStudio = self.MDRStudio + 0.9 * (1-self.MDRStudio)
        self.MDJuNote = self.MDJuNote + 0.9 * (1-self.MDJuNote)
        self.MDVSCode = self.MDVSCode + 0.1 * (1-self.MDVSCode)
        
        self.MNDPhpStorm = self.MNDPhpStorm + 0.8 * (1-self.MNDPhpStorm)
        self.MNDPyCharm = self.MNDPyCharm + 0.8 * (1-self.MNDPyCharm)
        self.MNDRStudio = self.MNDRStudio + 0.8 * (1-self.MNDRStudio)
        self.MNDIntelliJIDEA = self.MNDIntelliJIDEA + 0.8 * (1-self.MNDIntelliJIDEA)
        self.MNDAndroidStudio = self.MNDAndroidStudio + 0.8 * (1-self.MNDAndroidStudio)
        
        
    @Rule(
        Fact(answ="1-5"))
    def s5(self):
        self.MDXcode = self.MDXcode + 0.9 * (1-self.MDXcode)
        self.VSCode = self.VSCode + 0.1 * (1-self.VSCode)
        
        self.MNDPyCharm = self.MNDPyCharm + 0.8 * (1-self.MNDPyCharm)
        self.MNDJuNote = self.MNDJuNote + 0.8 * (1-self.MNDJuNote)
        self.MNDRStudio = self.MNDRStudio + 0.8 * (1-self.MNDRStudio)
        self.MNDIntelliJIDEA = self.MNDIntelliJIDEA + 0.8 * (1-self.MNDIntelliJIDEA)
        self.MNDPhpStorm = self.MNDPhpStorm + 0.8 * (1-self.MNDPhpStorm)
        self.MNDAndroidStudio = self.MNDAndroidStudio + 0.8 * (1-self.MNDAndroidStudio)
    
    
    @Rule(
        Fact(answ="2-2"))
    def f1(self):
        self.MNDIntelliJIDEA = self.MNDIntelliJIDEA + 0.6 * (1-self.MNDIntelliJIDEA)
        self.MNDPyCharm = self.MNDPyCharm + 0.6 * (1-self.MNDPyCharm)
        self.MNDPhpStorm = self.MNDPhpStorm + 0.6 * (1-self.MNDPhpStorm)
        
        self.MDJuNote = self.MDJuNote + 0.2 * (1-self.MDJuNote)
        self.MDRStudio = self.MDRStudio + 0.2 * (1-self.MDRStudio)
        self.MDXcode = self.MDXcode + 0.2 * (1-self.MDXcode)
        self.MDVSCode = self.MDVSCode + 0.2 * (1-self.MDVSCode)
        self.MDAndroidStudio = self.MDAndroidStudio + 0.2 * (1-self.MDAndroidStudio)

    
    @Rule(Fact(answ="2-1"))
    def f2(self):
        self.MDIntelliJIDEA = self.MDIntelliJIDEA + 0.2 * (1-self.MDIntelliJIDEA)
        self.MDPyCharm = self.MDPyCharm + 0.2 * (1-self.MDPyCharm)
        self.MDPhpStorm = self.MDPhpStorm + 0.2 * (1-self.MDPhpStorm)

        
        
    @Rule(Fact(answ="3-1") | Fact(answ="3-2"))
    def g1(self):
        self.MDIntelliJIDEA = self.MDIntelliJIDEA + 0.2 * (1-self.MDIntelliJIDEA)
        self.MDPyCharm = self.MDPyCharm + 0.2 * (1-self.MDPyCharm)
        self.MDPhpStorm = self.MDPhpStorm + 0.2 * (1-self.MDPhpStorm)
        self.MDJuNote = self.MDJuNote + 0.2 * (1-self.MDJuNote)
        self.MDRStudio = self.MDRStudio + 0.2 * (1-self.MDRStudio)
        self.MDVSCode = self.MDVSCode + 0.2 * (1-self.MDVSCode)
        self.MDAndroidStudio = self.MDAndroidStudio + 0.2 * (1-self.MDAndroidStudio)
        
        self.MNDXcode = self.MNDXcode + 0.9 * (1-self.MNDXcode)
        
        
    @Rule(Fact(answ="3-3") | Fact(answ="0-4"))
    def g2(self):
        self.MNDIntelliJIDEA = self.MNDIntelliJIDEA + 0.1 * (1-self.MNDIntelliJIDEA)
        self.MNDPyCharm = self.MNDPyCharm + 0.1 * (1-self.MNDPyCharm)
        self.MNDPhpStorm = self.MNDPhpStorm + 0.1 * (1-self.MNDPhpStorm)
        self.MNDRStudio = self.MNDRStudio + 0.1 * (1-self.MNDRStudio)
        
        self.MDVSCode = self.MDVSCode + 0.3 * (1-self.MDVSCode)
        self.MDJuNote = self.MDJuNote + 0.3 * (1-self.MDJuNote)
        self.MDXcode = self.MDXcode + 0.6 * (1-self.MDXcode)
    
    
    @Rule(Fact(answ="4-1") | Fact(answ="5-1"))
    def h1(self):
        self.MDIntelliJIDEA = self.MDIntelliJIDEA + 0.2 * (1-self.MDIntelliJIDEA)
        self.MDPyCharm = self.MDPyCharm + 0.2 * (1-self.MDPyCharm)
        self.MDPhpStorm = self.MDPhpStorm + 0.2 * (1-self.MDPhpStorm)
        self.MDVSCode = self.MDVSCode + 0.1 * (1-self.MDVSCode)
        self.MDXcode = self.MDXcode + 0.2 * (1-self.MDXcode)
        
        self.MNDRStudio = self.MNDRStudio + 0.5 * (1-self.MNDRStudio)
        self.MNDJuNote = self.MNDJuNote + 0.8 * (1-self.MNDJuNote)
    
    
    @Rule(Fact(answ="4-2") | Fact(answ="5-2"))
    def h2(self):
        self.MDIntelliJIDEA = self.MDIntelliJIDEA + 0.1 * (1-self.MDIntelliJIDEA)
        self.MDPyCharm = self.MDPyCharm + 0.1 * (1-self.MDPyCharm)
        self.MDPhpStorm = self.MDPhpStorm + 0.1 * (1-self.MDPhpStorm)
        self.MDVSCode = self.MDVSCode + 0.1 * (1-self.MDVSCode)
        self.MDXcode = self.MDXcode + 0.1 * (1-self.MDXcode)
        self.MDRStudio = self.MDRStudio + 0.2 * (1-self.MDRStudio)
        self.MDJuNote = self.MDJuNote + 0.2 * (1-self.MDJuNote)
        self.MDAndroidStudio = self.MDAndroidStudio + 0.2 * (1-self.MDAndroidStudio)
    
    
    @Rule(Fact(answ="4-3") | Fact(answ="5-3"))
    def h3(self):
        self.MDIntelliJIDEA = self.MDIntelliJIDEA + 0.1 * (1-self.MDIntelliJIDEA)
        self.MDPyCharm = self.MDPyCharm + 0.1 * (1-self.MDPyCharm)
        self.MDPhpStorm = self.MDPhpStorm + 0.1 * (1-self.MDPhpStorm)
        self.MDVSCode = self.MDVSCode + 0.1 * (1-self.MDVSCode)
        self.MDXcode = self.MDXcode + 0.1 * (1-self.MDXcode)
        self.MDRStudio = self.MDRStudio + 0.1 * (1-self.MDRStudio)
        self.MDJuNote = self.MDJuNote + 0.1 * (1-self.MDJuNote)
        self.MDAndroidStudio = self.MDAndroidStudio + 0.1 * (1-self.MDAndroidStudio)
    
    
    def getWeights(self):
        return {
            "IntelliJ IDEA": self.MDIntelliJIDEA - self.MNDIntelliJIDEA,
            "PyCharm": self.MDPyCharm - self.MNDPyCharm,
            "PhpStorm": self.MDPhpStorm - self.MNDPhpStorm,
            "Jupyter Notebook": self.MDJuNote - self.MNDJuNote,
            "RStudio": self.MDRStudio - self.MNDRStudio,
            "Xcode": self.MDXcode - self.MNDXcode,
            "Visual Studio Code": self.MDVSCode - self.MNDVSCode,
            'Android Studio': self.MDAndroidStudio - self.MNDAndroidStudio,
        }
        
        
    def checkRedactors(self):
        dct = self.getWeights()
        max_key = max(dct, key=dct.get)
        max_value = dct[max_key]
        return max_key, max_value
    
    
Questions = {
    0: "Укажите сферу для которой вы ищете редактор:\n",
    1: "Укажите основной язык:\n",
    2: "Готовы ли вы платить за использование редактора?\n",
    3: "Какую операционную систему вы используете?\n",
    4: "Нужна ли вам возможность интеграции с git?\n",
    5: "Требуется ли вам возможность отладки?\n"
}


Answers = {
    0:  
        "1 - Backend\n"
        "2 - Data Science\n"
        "3 - Game Development\n"
        "4 - Просто требуется редактор\n",
    1: 
        "1 - Java\n"
        "2 - Python\n"
        "3 - PHP\n"
        "4 - R\n"
        "5 - Swift\n",
    2: 
        "1 - Да\n"
        "2 - Нет\n",
        
    3:  
        "1 - Windows\n"
        "2 - Linux\n"
        "3 - MacOS\n",
    
    4:  
        "1 - Да\n"
        "2 - Нет\n"
        "3 - Не важно\n",

    5:  
        "1 - Да\n"
        "2 - Нет\n"
        "3 - Не важно\n",
}


    
if __name__ == "__main__":
    FindSolution = Solve()
    
    for i in Questions:
        print(Questions[i])
        
        x = str(input(Answers[i]))
        
        ans = str(i) + "-" + x
        FindSolution.declare(Fact(answ=ans))
        FindSolution.run()

    check = FindSolution.checkRedactors()
    print("Вам подходит редактор: " + check[0])