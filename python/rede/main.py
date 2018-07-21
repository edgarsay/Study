from models import Aluno

def test_answer():
    assert Aluno.auto_cadastro('teste.txt')[0].getNome() == 'ALEF DAYANNO DE LIMA SILVA\n'
    assert Aluno.auto_cadastro('teste.txt')[-1].getNome() == 'VITOR HUGO BARBOSA DOS SANTOS\n'

