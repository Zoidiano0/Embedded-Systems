datos = read.csv("Base.csv",header = TRUE, sep = ",")
revisar datos de matriz
View(datos)
#cargar Librerias
library(caTools)
library(NoiseFiltersR)

set.seed(123) #randon
#establecer valores de analisic
split= sample.split(datos$label,SplitRatio=0.8)
training_set = subset(datos, split==TRUE) #setear valores escojidos
test_set=subset(datos,split==FALSE)#setear valores desechados

#obtencio nde datos
training_set$label=factor(training_set$label,levels = c(1,2,3))
#funcion de datos
cnn_matrix=CNN(training_set,k=3)
print(cnn_matrix)
cnn_matrix=cnn_matrix$cleanData
#AENN CNN ENG ENN RNN DROP3

#AENN

aenn_matrix = ENN(training_set,k=3)
print(aenn_matrix)
aenn_matrix=aenn_matrix$cleanData

rnn_matrix = ENN(training_set,k=3)
print(aenn_matrix)
rnn_matrix=rnn_matrix$cleanData

###########KNN########

library(class)
y_pred=knn(train=aenn_matrix[,-6],test= test_set[,-6],cl=aenn_matrix[,6], k=3)
cm=table(test_set[,6],y_pred)

View(cm)

cm



