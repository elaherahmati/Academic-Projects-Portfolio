import math
import random
import xlwt
import statistics as st
from xlwt import Workbook
import matplotlib.pyplot as plt

# Get policy mode from user
Policy = int(input('Select Your Policy\n'
                   '0 for RR\n'
                   '1 for LIR\n'
                   '2 for SIR\n'
                   '3 for LTIR\n'))

# Making Trace Excel
wb = Workbook()
Style = xlwt.easyxf('font: bold 1,color red')  # Header Style
sheet1 = wb.add_sheet('Trace')  # Add sheet Trace
#Sheet1 and Headers
sheet1.write(0, 0, 'Row', Style)
sheet1.write(0, 1, 'Clock', Style)
sheet1.write(0, 2, 'Event', Style)
sheet1.write(0, 3, 'Message ID', Style)
sheet1.write(0, 4, 'FEL', Style)
sheet1.write(0, 5, 'Server 1 State', Style)
sheet1.write(0, 6, 'Server 2 State', Style)
sheet1.write(0, 7, 'Server 3 State', Style)
sheet1.write(0, 8, 'Server 4 State', Style)
sheet1.write(0, 9, 'Server 5 State', Style)
sheet1.write(0, 10, 'Last Idle Time Server 1', Style)
sheet1.write(0, 11, 'Last Idle Time Server 2', Style)
sheet1.write(0, 12, 'Last Idle Time Server 3', Style)
sheet1.write(0, 13, 'Last Idle Time Server 4', Style)
sheet1.write(0, 14, 'Last Idle Time Server 5', Style)
sheet1.write(0, 15, 'Cumulative Idle Time Server 1', Style)
sheet1.write(0, 16, 'Cumulative Idle Time Server 2', Style)
sheet1.write(0, 17, ' Cumulative Idle Time Server 3', Style)
sheet1.write(0, 18, 'Cumulative Idle Time Server 4', Style)
sheet1.write(0, 19, 'Cumulative Idle Time Server 5', Style)
sheet1.write(0, 20, 'Cumulative Idle Time Server 1 after warmup', Style)
sheet1.write(0, 21, 'Cumulative Idle Time Server 2 after warmup', Style)
sheet1.write(0, 22, 'Cumulative Idle Time Server 3 after warmup', Style)
sheet1.write(0, 23, 'Cumulative Idle Time Server 4 after warmup', Style)
sheet1.write(0, 24, 'Cumulative Idle Time Server 5 after warmup', Style)
sheet1.write(0, 25, 'Utilization server 1', Style)
sheet1.write(0, 26, 'Utilization server 2', Style)
sheet1.write(0, 27, 'Utilization server 3', Style)
sheet1.write(0, 28, 'Utilization server 4', Style)
sheet1.write(0, 29, 'Utilization server 5', Style)
sheet1.write(0, 30, 'Dismiss', Style)
sheet1.write(0, 31, 'Total Served', Style)
sheet1.write(0, 32, 'Recieved', Style)

#Sheet 2 and Headers
sheet2 = wb.add_sheet('Statistics')  # Add another sheet
sheet2.write(0, 0, 'Row', Style)
sheet2.write(0, 1, 'Proportion Server 0', Style)
sheet2.write(0, 2, 'Proportion Server 1', Style)
sheet2.write(0, 3, 'Proportion Server 2', Style)
sheet2.write(0, 4, 'Proportion Server 3', Style)
sheet2.write(0, 5, 'Proportion Server 4', Style)
sheet2.write(0, 6, 'Total idle time Server 0', Style)
sheet2.write(0, 7, 'Total idle time Server 1', Style)
sheet2.write(0, 8, 'Total idle time Server 2', Style)
sheet2.write(0, 9, 'Total idle time Server 3', Style)
sheet2.write(0, 10, 'Total idle time Server 4', Style)

# Attributes from t=0
Dismiss = 0  # Sum of missing messages
Served = 0  # Sum of served messages
Recieved = 0  # Sum of recieved messages
FEL = [['S', 0], ['E', 1000.0]]  # At t=0
Clock = 0  # Simulation Clock
IdleServer = []  # Real-time info about idle servers and times : [[Idle server ID,Last idle time,Cumulative idle time]]
Idle_ID = []  # Idle servers ID
Total_Idle = [0, 0, 0, 0, 0]  # Cumulative idle time
ServerState = [[0 for l in range(5)] for m in range(2)]  # First row :server state; Busy=1 Or Idle=0 / Second row : Finish Time of service
Total_Served = [0, 0, 0, 0, 0]  # Number of served messages by each server
x = []  # X axis of plot(time)
y = []  # Y axis of plot(Total Served messages/Total recieved messages
# Attributes from t=warmup
Dismiss_Statistic = 0  # Sum of missing messages
Served_Statistic = 0  # Sum of served messages
Recieved_Statistic = 0  # Sum of recieved messages
Statistics = []  # List for collecting both statistics of each server
Total_Idle_Statistic = [0, 0, 0, 0, 0]  # Cumulative idle time
Total_Served_Statistic = [0, 0, 0, 0, 0]  # Number of served messages by each server
Last_Update_Clock = 0  # Last time update of Total_Idle
Count = 0  # for recognizing first time after warup time
Message_ID=0

# Sort FEL by Time
def Sort():
    FEL.sort(key=lambda a: a[1])

# Arrival Event Generator,Update FEL
def Interarrival_Time_Generator():
    t = (-2.8) * math.log(random.random())
    FEL.append(['A', t + Clock, Message_ID])

# Update IdleServer List at any time for choosing server based on policy
def IdleServer_Update():
    for i in range(0, 5):
        if ServerState[0][i] == 0:
            IdleServer.append([i, Clock - ServerState[1][i], Total_Idle[i] + Clock - Last_Update_Clock])

# Update Total_Idle use for LTIR policy and collecting statistics
def Total_Idle_Update():
    #Idle Server IDs
    for i in range(0, len(IdleServer)):
        Idle_ID.append(IdleServer[i][0])

    for i in Idle_ID:
        Total_Idle[i] += Clock - Last_Update_Clock

        # Collecting statistic after warmup
        if Clock >= 150.0:
            if Count == 1:  # First time
                if ServerState[1][i] < 150.0:
                    Total_Idle_Statistic[i] += Clock - 150
                elif ServerState[1][i] >= 150.0:
                    Total_Idle_Statistic[i] += Clock - ServerState[1][i]
            else:
                Total_Idle_Statistic[i] += Clock - Last_Update_Clock

# Departure Event Generator,Update FEL: Function argument is the Selected Server ID By Policy Functions
def Service_Time_Generator(s):
    global Exp_Parameter  # exponential parameter
    if s == 0:
        Exp_Parameter = 6
    elif s == 1:
        Exp_Parameter = 8
    elif s == 2:
        Exp_Parameter = 10
    elif s == 3:
        Exp_Parameter = 12
    elif s == 4:
        Exp_Parameter = 14
    #Generating service time and appending to FEL
    t = (-Exp_Parameter) * math.log(random.random())
    FEL.append(['D', t + Clock, s,FEL[0][2]])
    #Update attributes
    ServerState[0][s] = 1  # Server is Busy Now
    ServerState[1][s] = Clock + t  # Server 's finish service time
    Total_Served[s] += 1
    if Clock >= 150.0:  # Collecting statistic after warmup
        Total_Served_Statistic[s] += 1

# Policies:

# Policy: RR
def RR_Policy():
    #Generate random value between 0,1
    R = random.random()
    # Generate random value between 0,Number of idle servers
    R = int(R * len(IdleServer))
    #Assign random value to a server
    s = IdleServer[R][0]  # Chosed server ID
    Service_Time_Generator(s)

# Policy: SIR
def SIR_Policy():
    IdleServer.sort(key=lambda a: a[1])  # Min Idle Time
    s = IdleServer[0][0]  # Chosed server ID
    Service_Time_Generator(s)

# Policy: LIR
def LIR_Policy():
    IdleServer.sort(key=lambda a: a[1], reverse=True)  # Max Idle Time
    s = IdleServer[0][0]  # Chosed server ID
    Service_Time_Generator(s)

# Policy: LTIR
def LTIR_Policy():
    IdleServer.sort(key=lambda a: a[2], reverse=True)  # Max Total Idle Time
    s = IdleServer[0][0]  # Chosed server ID
    Service_Time_Generator(s)

Row = 1  # Trace excel row numbers
Loop = 0  # counter for 700 loops

while Loop < 700:

    # Restarting attributes
    Dismiss = 0
    Served = 0
    Recieved = 0
    FEL = [['S', 0], ['E', 1000]]
    Clock = 0
    IdleServer = []
    Total_Idle = [0, 0, 0, 0, 0]
    ServerState = [[0 for l in range(5)] for m in range(2)]
    Total_Served = [0, 0, 0, 0, 0]
    Dismiss_Statistic = 0
    Served_Statistic = 0
    Recieved_Statistic = 0
    Total_Idle_Statistic = [0, 0, 0, 0, 0]
    Total_Served_Statistic = [0, 0, 0, 0, 0]
    Statistics = []
    Last_Update_Clock = 0
    Idle_ID = []
    Count = 0
    Message_ID=0
    x=[]
    y=[]

    # each 1000s
    while Clock <= 1000.00:
        #Number of events after warup time
        if Clock >= 150.0:
            Count += 1

        IdleServer = []
        Idle_ID = []
        IdleServer_Update()  # get info about idle servers
        Total_Idle_Update()  # Update info

        # Start
        if FEL[0][0] == 'S':
            Interarrival_Time_Generator()
            Message_ID += 1

        # End
        if FEL[0][0] == 'E':
            # last update of idle time
            for i in range(0, 5):
                if ServerState[1][i] < 1000.0:
                    Total_Idle_Statistic[i] += 1000.0 - ServerState[1][i]

        # Departure
        if FEL[0][0] == 'D':
            n = FEL[0][2]
            ServerState[0][n] = 0  # Server is Idle now

        # Arrival
        if FEL[0][0] == 'A':

            Recieved += 1

            if Clock >= 150.0:
                Recieved_Statistic += 1

            if min(ServerState[0]) == 0:  # At least one server is idle
                Served += 1
                if Clock >= 150.0:
                    Served_Statistic += 1

                # Choosing policy based on user 's input
                if Policy == 0:
                    RR_Policy()
                elif Policy == 1:
                    LIR_Policy()
                elif Policy == 2:
                    SIR_Policy()
                else:
                    LTIR_Policy()
            else:

                Dismiss += 1
                if Clock >= 150.0:
                    Dismiss_Statistic += 1

            Interarrival_Time_Generator()
            Message_ID += 1


        # Updating FEL & Clock
        Sort()

        # Write in Excel & draw Plot for first 1000s
        if Loop == 0:
            sheet1.write(Row, 0, Row)
            sheet1.write(Row, 1, Clock)
            sheet1.write(Row, 2, str(FEL[0][0]))

            if FEL[0][0]=='A':
                sheet1.write(Row, 3, FEL[0][2])
            elif FEL[0][0]=='D':
                sheet1.write(Row, 3, FEL[0][3])

            del FEL[0]
            sheet1.write(Row, 4, str(FEL))

            for i in range (0,5):
                sheet1.write(Row, i + 5, ServerState[0][i])

                if i in Idle_ID:
                    for j in range (0,len(IdleServer)):
                        if IdleServer[j][0]==i:
                            sheet1.write(Row, i + 10, IdleServer[j][1])
                            sheet1.write(Row, i + 15, IdleServer[j][2])
                else:
                    sheet1.write(Row, i + 10,"-")
                    sheet1.write(Row, i + 15,"-")

            # Statistics
            sheet1.write(Row, 20, Total_Idle_Statistic[0])
            sheet1.write(Row, 21, Total_Idle_Statistic[1])
            sheet1.write(Row, 22, Total_Idle_Statistic[2])
            sheet1.write(Row, 23, Total_Idle_Statistic[3])
            sheet1.write(Row, 24, Total_Idle_Statistic[4])
            #Cause it makes division by zero
            if sum(Total_Served_Statistic) > 0:
                sheet1.write(Row,25, Total_Served_Statistic[0] / Recieved_Statistic * 100)
                sheet1.write(Row, 26, Total_Served_Statistic[1] / Recieved_Statistic * 100)
                sheet1.write(Row, 27, Total_Served_Statistic[2] / Recieved_Statistic * 100)
                sheet1.write(Row, 28, Total_Served_Statistic[3] / Recieved_Statistic * 100)
                sheet1.write(Row, 29, Total_Served_Statistic[4] / Recieved_Statistic * 100)
            else:
                sheet1.write(Row, 25, 0)
                sheet1.write(Row, 26, 0)
                sheet1.write(Row, 27, 0)
                sheet1.write(Row, 28, 0)
                sheet1.write(Row, 29, 0)

            sheet1.write(Row, 30, Dismiss)
            sheet1.write(Row, 31, Served)
            sheet1.write(Row, 32, Recieved)

            Row += 1

            # X & Y
            if Recieved == 0:
                y.append(0)
            else:
                y.append(Served / Recieved)
            x.append(Clock)
        else:
            del FEL[0]

        Last_Update_Clock = Clock
        Clock = FEL[0][1]

    # Collecting the 1000s statistics
    Statistics = [list(map(lambda a: a / Served_Statistic * 100, Total_Served_Statistic)), Total_Idle_Statistic]

    # Writing statistics in Trace excel
    sheet2.write(Loop + 1, 0, Loop+1)
    sheet2.write(Loop + 1, 1, Statistics[0][0])
    sheet2.write(Loop + 1, 2, Statistics[0][1])
    sheet2.write(Loop + 1, 3, Statistics[0][2])
    sheet2.write(Loop + 1, 4, Statistics[0][3])
    sheet2.write(Loop + 1, 5, Statistics[0][4])
    sheet2.write(Loop + 1, 6, Statistics[1][0])
    sheet2.write(Loop + 1, 7, Statistics[1][1])
    sheet2.write(Loop + 1, 8, Statistics[1][2])
    sheet2.write(Loop + 1, 9, Statistics[1][3])
    sheet2.write(Loop + 1, 10, Statistics[1][4])

    Loop += 1


# Plot
plt.xlabel('Time')
plt.ylabel('Served Messages/Recieved Messages')
plt.title('Warmup Time')
plt.plot(x, y)
plt.show()

#Calculating Ave of statistics in sheet statistic of trace
sheet2.write(701 , 0, 'Average',Style)
sheet2.write(701 , 1, xlwt.Formula("Average(B2:B701)"))
sheet2.write(701 , 2 , xlwt.Formula("Average(C2:C701)"))
sheet2.write(701 , 3 , xlwt.Formula("Average(D2:D701)"))
sheet2.write(701 , 4 , xlwt.Formula("Average(E2:E701)"))
sheet2.write(701 , 5 , xlwt.Formula("Average(F2:F701)"))
sheet2.write(701 , 6 , xlwt.Formula("Average(G2:G701)"))
sheet2.write(701 , 7 , xlwt.Formula("Average(H2:H701)"))
sheet2.write(701 , 8 , xlwt.Formula("Average(I2:I701)"))
sheet2.write(701 , 9 , xlwt.Formula("Average(J2:J701)"))
sheet2.write(701 , 10 , xlwt.Formula("Average(K2:K701)"))
#Calculating SD of statistics in sheet statistic of trace
sheet2.write(702 , 0 ,'SD', Style)
sheet2.write(702 , 1, xlwt.Formula("sqrt(var(B2:B701))"))
sheet2.write(702 , 2, xlwt.Formula("sqrt(var(C2:C701))"))
sheet2.write(702 , 3 , xlwt.Formula("sqrt(var(D2:D701))"))
sheet2.write(702 , 4 , xlwt.Formula("sqrt(var(E2:E701))"))
sheet2.write(702 , 5 , xlwt.Formula("sqrt(var(F2:F701))"))
sheet2.write(702 , 6 , xlwt.Formula("sqrt(var(G2:G701))"))
sheet2.write(702 , 7 , xlwt.Formula("sqrt(var(H2:H701))"))
sheet2.write(702 ,8, xlwt.Formula("sqrt(var(I2:I701))"))
sheet2.write(702 ,9 , xlwt.Formula("sqrt(var(J2:J701))"))
sheet2.write(702 ,10 , xlwt.Formula("sqrt(var(K2:K701))"))

# Save TraceSheet
wb.save("Trace.xls")