create database clientes; 
use clientes;

create table clientes.clientes(
	id int not null primary key auto_increment,
	razao varchar(100),
	fantasia varchar(100),
	cnpjcpf varchar(100),
	empresa bool,
	endereco varchar(100),
	cidade varchar(20),
	estado varchar(20),
	pais varchar(20),
	ativo varchar(1)
);

create table clientes.categorias(
	id int not null primary key auto_increment,
	nome varchar(100),
);

create table clientes.produtos(
	id int not null primary key auto_increment,
	nome varchar(100),
	lote varchar(100),
	validade varchar(100),
	cor varchar(100),
	valor varchar(100),
	idCategoria int not null,
	foreign key idCategoria references categorias(categorias.id),
	cliente int not null,
	foreign key references clientes(clientes.id),
	tamanho varchar(100)
);
