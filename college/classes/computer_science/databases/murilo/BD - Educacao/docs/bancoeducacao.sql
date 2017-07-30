-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKSç, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`Professor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Professor` (
  `idProfessor` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NULL,
  `DataNasc` DATE NULL,
  `DataContratação` DATE NULL,
  `CPF` VARCHAR(45) NULL,
  `RG` VARCHAR(45) NULL,
  PRIMARY KEY (`idProfessor`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Instituto`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Instituto` (
  `idInstituto` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NULL,
  PRIMARY KEY (`idInstituto`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Departamento`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Departamento` (
  `idDepartamento` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NULL,
  `Instituto_idInstituto` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`idDepartamento`),
  INDEX `fk_Departamento_Instituto_idx` (`Instituto_idInstituto` ASC),
  CONSTRAINT `fk_Departamento_Instituto`
    FOREIGN KEY (`Instituto_idInstituto`)
    REFERENCES `mydb`.`Instituto` (`idInstituto`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Curso`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Curso` (
  `idCurso` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NOT NULL,
  `Duracao` INT NOT NULL,
  `CreditosForm` VARCHAR(45) NOT NULL,
  `Departamento_idDepartamento` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`idCurso`),
  INDEX `fk_Curso_Departamento1_idx` (`Departamento_idDepartamento` ASC),
  CONSTRAINT `fk_Curso_Departamento1`
    FOREIGN KEY (`Departamento_idDepartamento`)
    REFERENCES `mydb`.`Departamento` (`idDepartamento`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Projeto`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Projeto` (
  `idProjeto` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NOT NULL,
  `Descricao` VARCHAR(45) NOT NULL,
  `Área de Pesquisa` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idProjeto`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Aluno`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Aluno` (
  `idAluno` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NOT NULL,
  `DataNasc` DATE NOT NULL,
  `CPF` VARCHAR(45) NOT NULL,
  `DataIngresso` DATE NOT NULL,
  `RG` VARCHAR(45) NOT NULL,
  `Matrícula` VARCHAR(45) NOT NULL,
  `Curso_idCursos` INT UNSIGNED NOT NULL,
  `Foto` VARCHAR(45) NULL,
  `Projeto_idProjeto` INT UNSIGNED NULL,
  PRIMARY KEY (`idAluno`),
  INDEX `fk_Aluno_Curso1_idx` (`Curso_idCursos` ASC),
  INDEX `fk_Aluno_Projeto1_idx` (`Projeto_idProjeto` ASC),
  CONSTRAINT `fk_Aluno_Curso1`
    FOREIGN KEY (`Curso_idCursos`)
    REFERENCES `mydb`.`Curso` (`idCurso`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Aluno_Projeto1`
    FOREIGN KEY (`Projeto_idProjeto`)
    REFERENCES `mydb`.`Projeto` (`idProjeto`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Disciplina`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Disciplina` (
  `idDisciplinas` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NOT NULL,
  `Código` INT NOT NULL,
  `Créditos` INT NULL,
  `Departamento_idDepartamento` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`idDisciplinas`),
  INDEX `fk_Disciplina_Departamento1_idx` (`Departamento_idDepartamento` ASC),
  CONSTRAINT `fk_Disciplina_Departamento1`
    FOREIGN KEY (`Departamento_idDepartamento`)
    REFERENCES `mydb`.`Departamento` (`idDepartamento`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Sala`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Sala` (
  `idSalas` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Numero` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idSalas`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Pre-requisito`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Pre-requisito` (
  `Disciplinas_idDisciplinas` INT UNSIGNED NULL,
  `Disciplinas_idDisciplinas1` INT UNSIGNED NULL,
  `idPre-requisito` INT NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`idPre-requisito`),
  INDEX `fk_Disciplinas_has_Disciplinas_Disciplinas2_idx` (`Disciplinas_idDisciplinas1` ASC),
  INDEX `fk_Disciplinas_has_Disciplinas_Disciplinas1_idx` (`Disciplinas_idDisciplinas` ASC),
  CONSTRAINT `fk_Disciplinas_has_Disciplinas_Disciplinas1`
    FOREIGN KEY (`Disciplinas_idDisciplinas`)
    REFERENCES `mydb`.`Disciplina` (`idDisciplinas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Disciplinas_has_Disciplinas_Disciplinas2`
    FOREIGN KEY (`Disciplinas_idDisciplinas1`)
    REFERENCES `mydb`.`Disciplina` (`idDisciplinas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Turma`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Turma` (
  `idTurma` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Letra` CHAR(1) NOT NULL,
  `Disciplina_idDisciplinas` INT UNSIGNED NULL,
  `Professor_idProfessor` INT UNSIGNED NULL,
  `Sala_idSalas` INT UNSIGNED NULL,
  PRIMARY KEY (`idTurma`, `Disciplina_idDisciplinas`),
  INDEX `fk_Turma_Disciplina1_idx` (`Disciplina_idDisciplinas` ASC),
  INDEX `fk_Turma_Professor1_idx` (`Professor_idProfessor` ASC),
  INDEX `fk_Turma_Sala1_idx` (`Sala_idSalas` ASC),
  CONSTRAINT `fk_Turma_Disciplina1`
    FOREIGN KEY (`Disciplina_idDisciplinas`)
    REFERENCES `mydb`.`Disciplina` (`idDisciplinas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Turma_Professor1`
    FOREIGN KEY (`Professor_idProfessor`)
    REFERENCES `mydb`.`Professor` (`idProfessor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Turma_Sala1`
    FOREIGN KEY (`Sala_idSalas`)
    REFERENCES `mydb`.`Sala` (`idSalas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Matricula`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Matricula` (
  `Aluno_idAluno` INT UNSIGNED NULL,
  `Turma_idTurma` INT UNSIGNED NOT NULL,
  `Turma_Disciplina_idDisciplinas` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`Turma_idTurma`, `Turma_Disciplina_idDisciplinas`, `Aluno_idAluno`),
  INDEX `fk_Aluno_has_Turma_Turma1_idx` (`Turma_idTurma` ASC, `Turma_Disciplina_idDisciplinas` ASC),
  INDEX `fk_Aluno_has_Turma_Aluno1_idx` (`Aluno_idAluno` ASC),
  CONSTRAINT `fk_Aluno_has_Turma_Aluno1`
    FOREIGN KEY (`Aluno_idAluno`)
    REFERENCES `mydb`.`Aluno` (`idAluno`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Aluno_has_Turma_Turma1`
    FOREIGN KEY (`Turma_idTurma` , `Turma_Disciplina_idDisciplinas`)
    REFERENCES `mydb`.`Turma` (`idTurma` , `Disciplina_idDisciplinas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Laboratorio`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Laboratorio` (
  `idLaboratório` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NULL,
  `Sala_idSalas` INT UNSIGNED NULL,
  `Departamento_idDepartamento` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`idLaboratório`),
  INDEX `fk_Laboratorio_Sala1_idx` (`Sala_idSalas` ASC),
  INDEX `fk_Laboratorio_Departamento1_idx` (`Departamento_idDepartamento` ASC),
  CONSTRAINT `fk_Laboratorio_Sala1`
    FOREIGN KEY (`Sala_idSalas`)
    REFERENCES `mydb`.`Sala` (`idSalas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Laboratorio_Departamento1`
    FOREIGN KEY (`Departamento_idDepartamento`)
    REFERENCES `mydb`.`Departamento` (`idDepartamento`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Tipo_Item`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Tipo_Item` (
  `idTipo_Item` INT NOT NULL,
  `Nome` VARCHAR(45) NOT NULL,
  `Tipo_Itemcol` VARCHAR(45) NOT NULL,
  `Descricao` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idTipo_Item`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Item`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Item` (
  `idItem` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NOT NULL,
  `Quantidade` VARCHAR(45) NOT NULL,
  `Descricao` VARCHAR(45) NULL,
  `Tipo_Item_idTipo_Item` INT NOT NULL,
  `Laboratorio_idLaboratório` INT UNSIGNED NULL,
  PRIMARY KEY (`idItem`),
  INDEX `fk_Item_Tipo_Item1_idx` (`Tipo_Item_idTipo_Item` ASC),
  INDEX `fk_Item_Laboratorio1_idx` (`Laboratorio_idLaboratório` ASC),
  CONSTRAINT `fk_Item_Tipo_Item1`
    FOREIGN KEY (`Tipo_Item_idTipo_Item`)
    REFERENCES `mydb`.`Tipo_Item` (`idTipo_Item`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Item_Laboratorio1`
    FOREIGN KEY (`Laboratorio_idLaboratório`)
    REFERENCES `mydb`.`Laboratorio` (`idLaboratório`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Projeto_Prof`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Projeto_Prof` (
  `idProjeto_Prof` INT NOT NULL AUTO_INCREMENT,
  `Projeto_idProjeto` INT UNSIGNED NOT NULL,
  `Professor_idProfessor` INT UNSIGNED NOT NULL,
  INDEX `fk_Projeto_has_Professor_Professor1_idx` (`Professor_idProfessor` ASC),
  INDEX `fk_Projeto_has_Professor_Projeto1_idx` (`Projeto_idProjeto` ASC),
  PRIMARY KEY (`idProjeto_Prof`),
  CONSTRAINT `fk_Projeto_has_Professor_Projeto1`
    FOREIGN KEY (`Projeto_idProjeto`)
    REFERENCES `mydb`.`Projeto` (`idProjeto`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Projeto_has_Professor_Professor1`
    FOREIGN KEY (`Professor_idProfessor`)
    REFERENCES `mydb`.`Professor` (`idProfessor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
