FROM nlknguyen/alpine-mpich

COPY . /app

WORKDIR /app

RUN sudo mpicc -o  hello hello.c

CMD mpirun -np 2 ./hello

# Run the following commands in the terminal with directory ~/D1$

# sudo docker run -dit --name quicksort1 ubuntu

# sudo docker run -dit --name quicksort2 ubuntu

# sudo docker build -t mpiproj .

# sudo docker run mpiproj

# sudo docker ps