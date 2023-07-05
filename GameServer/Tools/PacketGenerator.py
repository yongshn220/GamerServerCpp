import argparse
import jinja2
import ProtoParser

def main():
    arg_parser = argparse.ArgumentParser(description='PacketGenerator')
    arg_parser.add_argument('--path', type=str, default='C:/Users/yongjung/private/gameServer/GameServer/Common/protobuf/bin/Protocol.proto', help='proto path')
    arg_parser.add_argument('--output', type=str, default='TestPacketHandler', help='output file')
    arg_parser.add_argument('--recv', type=str, default='C_', help='recv convention')
    arg_parser.add_argument('--send', type=str, default='S_', help='send convention')
    args = arg_parser.parse_args()

    parser = ProtoParser.ProtoParser(1000, args.recv, args.send)
    parser.parse_proto(args.path)


    return


if __name__ == '__main__':
    main()
