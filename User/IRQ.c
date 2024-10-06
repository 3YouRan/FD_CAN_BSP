////
//// Created by ��� on 24-9-18.
////
#include "all.h"
//
///*
// * @brief CAN�������ݻص�����
// *
// * @param hcan CAN���
// *
// * @return None
// */
//uint32_t CAN_Get_times=0;
//int16_t Start_angle_1=0;
//int16_t theta_2_last=0;
//int16_t theta_2_last_last=0;
//int16_t theta_2=0;
//void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
//
//    CAN_RxHeaderTypeDef rx_header;
//    uint8_t             rx_data[8];
//    if(hcan->Instance == CAN1)
//    {
//        CAN_Get_times++;
//        HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data); //receive can data
////        printf("CAN_get_id:%x\r\n",rx_header.StdId);
//        switch(rx_header.StdId)
//        {
//            case 0x201:
//            {
//                if(CAN_Get_times<=100){//���ڵ��ת�ӵĳ�ʼ��е�ǶȲ�һ��Ϊ0�����оƬ���ϵ�ʱ����ȡ���ĵ��ʵ�ʽǶȿ��ܲ�Ϊ0,��λ�û��������¿��ܵ��µ���ϵ�ʱƫ���ʼλ��
//                    Start_angle_1    = ((rx_data[0] << 8) | rx_data[1]);//��˼�¼���ת�ӵĳ�ʼ��е�Ƕȣ�������λ�û����������ĳ�ʼƯ�ơ�
////                    Start_angle_1= transfer(Start_angle_1, 0, 8191, -pi / 36.0, pi / 36.0);
//                }else{
//                    gm2006_1.rotor_angle    = ((rx_data[0] << 8) | rx_data[1])-Start_angle_1;
//                    gm2006_1.rotor_speed    = ((rx_data[2] << 8) | rx_data[3]);
//                    gm2006_1.torque_current = ((rx_data[4] << 8) | rx_data[5]);
//                }
//
//
////                gm2006_1.temp           =   rx_data[6];
////                printf("CAN_get_id:%x\r\n",rx_header.StdId);
//
//
//                break;
//            }
//            case 0x202:{
//                gm2006_2.rotor_angle    = ((rx_data[0] << 8) | rx_data[1]);
//                gm2006_2.rotor_speed    = ((rx_data[2] << 8) | rx_data[3]);
//                gm2006_2.torque_current = ((rx_data[4] << 8) | rx_data[5]);
//
//
//                break;
//            }
//
//        }
//    }
//    if(hcan->Instance == CAN2)
//    {
////        uint8_t send_data[8]="get_id!";
//        HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data); //receive can data
////        printf("CAN_get_id:%x\r\n",rx_header.StdId);
//        switch(rx_header.StdId)
//        {
//            case 0x405:{
//
//                theta_2=((int16_t)((rx_data[0]<<8)|(rx_data[1])));
//                if(theta_2_last!=theta_2&&theta_2_last_last==theta_2_last) {
//                    theta = theta_2 / 1000.0;
//                    xSemaphoreGiveFromISR(g_SemaphoreHandle_For_Kinematics, NULL);//ʹ���ź�������Kinematics����
//                    printf("theta=%d,%X\n", theta, theta_2);
//                }
//                theta_2_last_last=theta_2_last;
//                theta_2_last=theta_2;
//                xSemaphoreGiveFromISR(g_SemaphoreHandle_For_Kinematics, NULL);//ʹ���ź�������Kinematics����
//
//                break;
//            }
//        }
//    }
//
//}
///*
// * @brief UART�������ݻص�����
// *
// * @param huart UART���
// * @return None
// */
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//
//
//    if(huart==&huart4)
//    {
//        RxLine++;                      //每接收到�?个数据，进入回调数据长度�?1
//        DataBuff[RxLine-1]=RxBuffer[0];  //把每次接收到的数据保存到缓存数组
//        if(RxBuffer[0]=='!')           //接收结束标志�?
//        {
//            printf("RXLen=%d\r\n",RxLine);
//            for(int i=0;i<RxLine;i++)
//                printf("UART DataBuff[%d] = %c\r\n",i,DataBuff[i]);
////            xEventGroupSetBitsFromISR(g_xEventGroup_Uart_Rx,(1<<0),NULL);
//
//            USART_PID_Adjust(1);//数据解析和参数赋值函�?
//
//            memset(DataBuff,0,sizeof(DataBuff));  //清空缓存数组
//            RxLine=0;  //清空接收长度
//            xSemaphoreGiveFromISR(g_SemaphoreHandle_For_Uart_RX, NULL);//ʹ���ź�������UART_Rx����
//
//        }
//        RxBuffer[0]=0;
//        HAL_UART_Receive_IT(&huart4, (uint8_t *)RxBuffer, 1);//每接收一个数据，就打�?�?次串口中断接�?
//    }
//}
//
//
///**
//  * @brief ������ģʽ�µ� Period elapsed �ص�
//  * @note �� TIM4 �жϷ���ʱ����
//  * HAL_TIM_IRQHandler���� ����ֱ�ӵ��� HAL_IncTick���� �Ե���
//  * ����Ӧ�ó���ʱ����ȫ�ֱ��� ��uwTick����
//  * @param htim �� TIM ���
//  * @retval ��
//  */
//uint8_t time1=0;
////int16_t current_1=0;
////int16_t current_2=0;
////float angle_now_1=0,angle_last_1=0,angle_total_1=0;//���λ��ͳ��
////float angle_now_2=0,angle_last_2=0,angle_total_2=0;
////bool Pos_flag=1;//�Ƿ���λ�ÿ���
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//    /* USER CODE BEGIN Callback 0 */
//
//    /* USER CODE END Callback 0 */
//    if (htim->Instance == TIM4) {
//        HAL_IncTick();
//    }
//    /* USER CODE BEGIN Callback 1 */
//    if(htim->Instance==TIM3){
//        time1++;
//
//        angle_last_1=angle_now_1;
//        angle_last_2=angle_now_2;
//
//        angle_now_1 = transfer(gm2006_1.rotor_angle, 0-Start_angle_1, 8191-Start_angle_1, -pi / 36.0, pi / 36.0);
//        angle_now_2 = transfer(gm2006_2.rotor_angle, 0, 8191, -pi / 36.0, pi / 36.0);
//        if(angle_now_1 - angle_last_1 > (pi / 36.0)){
//            angle_total_1+=(angle_now_1 - angle_last_1 - 2 * pi / 36.0);
//        }else if(angle_now_1 - angle_last_1 < (-pi / 36.0))
//        {
//            angle_total_1+=(angle_now_1 - angle_last_1 + 2 * pi / 36.0);
//        }else{
//            angle_total_1+=(angle_now_1 - angle_last_1);
//        }
//        if(angle_now_2 - angle_last_2 > (pi / 36.0)){
//            angle_total_2+=(angle_now_2 - angle_last_2 - 2 * pi / 36.0);
//        }else if(angle_now_2 - angle_last_2 < (-pi / 36.0))
//        {
//            angle_total_2+=(angle_now_2 - angle_last_2 + 2 * pi / 36.0);
//        }else{
//            angle_total_2+=(angle_now_2 - angle_last_2);
//        }
//
//        if(time1==5){
//            time1=0;
//
////            if(Pos_flag) {//(theta)>0?(theta):(theta+0.1)
////                Target_Speed_1 = FW_PID_Realize(&pid_position,//λ�û�
////                                                (theta)>0?(theta):(theta+0.1),
////                                                angle_total_1);//����¼�ĵ��ת�ӳ�ʼ��е�ǶȲ�����λ�û����������ĳ�ʼƯ�ơ�
////                Target_Speed_2 = FW_PID_Realize(&pid_position,
////                                                Target_Position_2,
////                                                angle_total_2);
//////            printf("Target_Speed_1:%f,%f\n",Target_Speed_1,theta);
////            }
////            //�ٶȻ�
////            current_1=FW_PID_Realize(&pid_speed, Target_Speed_actual_1, gm2006_1.rotor_speed / 36.0);
////            current_2=FW_PID_Realize(&pid_speed, Target_Speed_actual_2, gm2006_2.rotor_speed / 36.0);
//////            printf("Target_Speed_1:%d,%.2f,%d,%d\n",current_1,angle_total_1,gm2006_1.rotor_angle,gm2006_2.rotor_angle);
////
////            //�ٶ�����
////            if((Target_Speed_1 - Target_Speed_actual_1) > MIN_Spe_Increment){
////                Target_Speed_actual_1+=MIN_Spe_Increment;
////            } else if((Target_Speed_1 - Target_Speed_actual_1) < -MIN_Spe_Increment){
////                Target_Speed_actual_1-=MIN_Spe_Increment;
////            }
////            if((Target_Speed_2 - Target_Speed_actual_2) > MIN_Spe_Increment){
////                Target_Speed_actual_2+=MIN_Spe_Increment;
////            } else if((Target_Speed_2 - Target_Speed_actual_2) < -MIN_Spe_Increment){
////                Target_Speed_actual_2-=MIN_Spe_Increment;
////            }
////            //���͵��can�����ź�
////            GM2006_Current_Set(&hcan1, current_1, current_2, 0, 0, 0x200, GM_ID(1) | GM_ID(2));
////            xSemaphoreGiveFromISR(g_SemaphoreHandle_For_Pid, NULL);//ʹ���ź�������PID����
//        }
//    }
//    /* USER CODE END Callback 1 */
//}

/*
 * @brief FDCAN�������ݻص����� ��׼֡�������FIFO0����չ֡�������FIFO1
 *
 * @param hfdcan FDCAN���
 * @param RxFifo0ITs/RxFifo1ITs ����FIFO0/FIFO1�жϴ���
 *
 * @return None
 */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs){
    if(hfdcan->Instance == FDCAN1){
        FDCAN_RxHeaderTypeDef rx_header;
        uint8_t rx_data[8];
        HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &rx_header, rx_data); //receive can data
        printf("FDCAN_FIFO0_get:id=%x,data=%x\r\n",rx_header.Identifier,rx_data[0]);
        switch(rx_header.Identifier){

        }
    }
}
/*
 * @brief FDCAN�������ݻص����� ��׼֡�������FIFO0����չ֡�������FIFO1
 *
 * @param hfdcan FDCAN���
 * @param RxFifo0ITs/RxFifo1ITs ����FIFO0/FIFO1�жϴ���
 *
 * @return None
 */
void HAL_FDCAN_RxFifo1Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs){
    if(hfdcan->Instance == FDCAN1){
        FDCAN_RxHeaderTypeDef rx_header;
        uint8_t rx_data[8];
        HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO1, &rx_header, rx_data); //receive can data
//        printf("FDCAN_FIFO1_get:id=%x,data=%x\r\n",rx_header.Identifier,rx_data[0]);
        switch(rx_header.Identifier){

        }
    }
}
