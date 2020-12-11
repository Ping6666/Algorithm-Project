# -*- coding: utf-8 -*-
"""
Created on Wed May 20 14:42:33 2020

@author: user
"""
#引入各項需要的lib
import os
import numpy as np
from PIL import Image
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten
from keras.layers import Conv2D, MaxPooling2D
from keras.utils import np_utils
from matplotlib import pyplot as plt


def data_x_y_preprocess(datapath):
    img_row, img_col = 28, 28  #圖片大小28*28
    datapath = datapath  #資料路徑
    data_x = np.zeros((28, 28)).reshape(1, 28, 28)  #儲存圖片
    pictureCount = 0  #紀錄圖片數量以便reshape
    data_y = []  #紀錄label
    num_class = 10  #圖片種類有10種
    for root, dirs, files in os.walk(datapath):  #遍歷所有路境內的檔案
        for f in files:  #找出檔案
            label = int(root.split("\\")[2])  #取得label
            data_y.append(label)  #將label放入data_y
            fullpath = os.path.join(root, f)  #求出正確的fullpath
            img = Image.open(fullpath)  #開啟照片
            img = (np.array(img) / 255).reshape(1, 28, 28)  #正確讀出照片並且reshape
            data_x = np.vstack((data_x, img))  #處理完成後加入data_x
            pictureCount += 1  #圖片數量+1
    data_x = np.delete(data_x, [0], 0)  #刪除原先宣告的np.zeros
    data_x = data_x.reshape(pictureCount, img_row, img_col, 1)  #調整格式
    data_y = np_utils.to_categorical(data_y,
                                     num_class)  #將label轉成one-hot encoding
    return data_x, data_y  #回傳所有處理好的資料


#從train_image資料夾取得資料
data_train_X, data_train_Y = data_x_y_preprocess("train_image")

model = Sequential()  #建立線性執行模型

#建立卷基層，filters=32，即output size層數，kernel_size=3*3，並且使用relu
model.add(
    Conv2D(32, kernel_size=(3, 3), activation='relu', input_shape=(28, 28, 1)))
model.add(MaxPooling2D(pool_size=(2, 2)))  #建立池化層，大小2*2，取最大值

#建立卷基層，filters=64，即output size層數，kernel_size=3*3，並且使用relu
model.add(Conv2D(64, (3, 3), activation='relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))  #建立池化層，大小2*2，取最大值

model.add(Dropout(0.1))  #防止過度擬合，隨機Dropout神經元，段開比例0.1
model.add(Flatten())  #使用Flatten將維的輸入一維化，使用於卷積層道全連接層的過度
model.add(Dropout(0.1))  #防止過度擬合，隨機Dropout神經元，段開比例0.1
model.add(Dense(128, activation='relu'))  #建立全連階層，128個輸出，並且使用relu
model.add(Dropout(0.25))  #防止過度擬合，隨機Dropout神經元，段開比例0.25
model.add(Dense(units=10, activation='softmax'))  #建立全連階層，10個輸出，並且使用softmax

model.summary()  #總結輸出現在連接狀態

#編譯，選擇損失函數、優化方式及成效衡量方式
model.compile(loss="categorical_crossentropy",
              optimizer="adam",
              metrics=['accuracy'])

#訓練過程，儲存於train_history之中，代數150，且用0.1的資料做檢查
train_history = model.fit(data_train_X,
                          data_train_Y,
                          batch_size=32,
                          epochs=200,
                          verbose=1,
                          validation_split=0.1)

#從test_image資料夾取得資料
data_test_X, data_test_Y = data_x_y_preprocess("test_image")

#顯示損失函數，個階段訓練成果
score = model.evaluate(data_test_X, data_test_Y, verbose=0)
print('Test loss:', score[0])  #輸出Test loss
print('Test accuracy:', score[1])  #輸出Test accuracy

#輸出訓練曲線
plt.plot(train_history.history['loss'])  #輸出訓練過程中的loss
plt.plot(train_history.history['val_loss'])  #輸出訓練過程中的val_loss
plt.title('Train History')  #圖片title
plt.ylabel('loss')  #圖片ylabel
plt.xlabel('Epoch')  #圖片xlabel
plt.legend(['loss', 'val_loss'], loc='upper left')  #圖片圖例
plt.show()  #圖片輸出
